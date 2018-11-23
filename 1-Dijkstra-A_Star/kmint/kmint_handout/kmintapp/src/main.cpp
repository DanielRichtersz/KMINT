#include "kmint/main.hpp" // voor de main loop
#include "cow.hpp"
#include "hare.hpp"
#include "kmint/graphics.hpp"      // kleuren en afbeeldingen
#include "kmint/map/map.hpp"       // voor kaarten
#include "kmint/math/vector2d.hpp" // voor window en app
#include "kmint/play.hpp"          // voor stage
#include "kmint/ui.hpp"            // voor window en app
#include <iostream>

using namespace kmint; // alles van libkmint bevindt zich in deze namespace

class rectangle_drawable : public ui::drawable {
public:
  rectangle_drawable(play::actor const &actor) : drawable{}, actor_{&actor} {}
  void draw(ui::frame &f) const override;

private:
  play::actor const *actor_;
};

void rectangle_drawable::draw(ui::frame &f) const {
  f.draw_rectangle(actor_->location(), {10.0, 10.0}, graphics::colors::white);
}

class hello_actor : public play::free_roaming_actor {
public:
  hello_actor(math::vector2d location)
      : free_roaming_actor{location}, drawable_{*this} {}

  const ui::drawable &drawable() const override { return drawable_; }
  void move(math::vector2d delta) { location(location() + delta); }

private:
  rectangle_drawable drawable_;
  // rectangle_drawable drawable_;
};

static const char *map_description = R"graph(32 24 32
resources/firstmap.png
G 1 1
C 1 1
H 1 1
W 0 0
B 1 8

WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WWWHGGGGGGGGGGGGGGGGGGGGGGGGHWWW
WWWGGGGGGGGGGGGGGGGGGGGGGGGGGWWW
WWWGGGGGGGGGGGGGBGGGGGGGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGWWWWWGGBGWWWWWGGGGGGWWW
WWWGGGGGGWWWWWGGGGWWWWWGGGGGGWWW
WWWGGGGGGWWWWWGGGGWWWWWGGGGGGWWW
WWWGGGGGBBBBBBBGCGGGGGGGGGGGGWWW
WWWGGGGGGWWWWWGGGGWWWWWGGGGGGWWW
WWWGGGGGGWWWWWGGBGWWWWWGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGWWWWWWWBWWWWWWGGGGGGWWW
WWWGGGGGGGGGGGGGBGGGGGGGGGGGGWWW
WWWGGGGGGGGGGGGGGGGGGGGGGGGGGWWW
WWWHGGGGGGGGGGGGGGGGGGGGGGGGHWWW
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
)graph";

const map::map_node &find_cow_node(const map::map_graph &graph) {
  for (std::size_t i = 0; i < graph.num_nodes(); ++i) {
    if (graph[i].node_info().kind == 'C') {
      return graph[i];
    }
  }
  throw "could not find starting point";
}

int main() {
  // een app object is nodig om
  ui::app app{};

  //  maak een venster aan
  ui::window window{app.create_window({1024, 768}, "hello")};

  // maak een podium aan
  play::stage s{};

  // laad een kaart
  map::map m{map::read_map(map_description)};
  auto &graph = m.graph();
  for (std::size_t i = 0; i < graph.num_nodes(); ++i) {
    graph[i].tagged(i % 2 == 0);
  }
  auto &node = graph[0];
  for (std::size_t i = 0; i < node.num_edges(); ++i) {
    auto &from = node[i].from();
    auto &to = node[i].to();
    std::cout << "Kant van: " << from.location().x() << ", "
              << from.location().y() << " naar " << to.location().x() << ", "
              << to.location().y() << "\n";
  }

  // plaats achtergrond afbeelding op scherm
  s.build_actor<play::background>(math::size(1024, 768),
                                  graphics::image{m.background_image()});
  s.build_actor<play::map_actor>(math::vector2d{0.0f, 0.0f}, m.graph());

  auto &cow_node = find_cow_node(m.graph());
  auto &my_cow = s.build_actor<cow>(m.graph(), cow_node);
  auto &my_hare = s.build_actor<hare>(m.graph());
  my_hare.set_cow(my_cow);

  math::vector2d center{cow_node.location().x(), cow_node.location().y()};
  auto &my_actor = s.build_actor<hello_actor>(center);

  // Maak een event_source aan (hieruit kun je alle events halen, zoals
  // toetsaanslagen)
  ui::events::event_source event_source{};

  // main_loop stuurt alle actors aan.
  main_loop(s, window, [&](delta_time dt, loop_controls &ctl) {
    // gebruik dt om te kijken hoeveel tijd versterken is
    // sinds de vorige keer dat deze lambda werd aangeroepen
    // loop controls is een object met eigenschappen die je kunt gebruiken om de
    // main-loop aan te sturen.

    for (ui::events::event &e : event_source) {
      // event heeft een methode handle_quit die controleert
      // of de gebruiker de applicatie wilt sluiten, en zo ja
      // de meegegeven functie (of lambda) aanroept om met het
      // bijbehorende quit_event
      //
      e.handle_quit([&ctl](ui::events::quit_event qe) { ctl.quit = true; });
      e.handle_key_up([&my_actor](ui::events::key_event k) {
        switch (k.key) {
        case ui::events::key::up:
          my_actor.move({0, -5.0f});
          break;
        case ui::events::key::down:
          my_actor.move({0, 5.0f});
          break;
        case ui::events::key::left:
          my_actor.move({-5.0f, 0});
          break;
        case ui::events::key::right:
          my_actor.move({5.0f, 0});
          break;
        default:
          break;
        }
      });
    }
  });
}
/*
#include "cow.hpp"
#include "graph.hpp"
#include "hare.hpp"
#include "kmint/graphics/image.hpp"
#include "kmint/main.hpp"
#include "kmint/map/map.hpp"
#include "kmint/math/size.hpp"
#include "kmint/math/vector2d.hpp"
#include "kmint/play.hpp"
#include "kmint/primitives.hpp"
#include "kmint/random.hpp"
#include "kmint/ui.hpp"
#include "resources.hpp"
#include <iostream>
#include <sstream>

using namespace kmint;

int main() {
  // Get the map and graph
  auto m = kmintapp::build_map();
  auto &g = m.graph();

  // the window will be equal to the size of the map's background image
  math::isize window_size{m.size().width(), m.size().height()};

  // create an app in which to run our simulation
  ui::app app{};
  ui::window window{app.create_window(window_size, "kmintapp")};

  // build a stage on which to place our actors (the cow and the hare)
  play::stage s{};

  s.build_actor<play::background>(
      math::size(window_size.width(), window_size.height()),
      graphics::image{m.background_image()});
  s.build_actor<play::graph_actor<map::map_graph>>(math::vector2d{0.0f, 0.0f},
                                                   g);
  auto &cow = s.build_actor<kmintapp::cow>(g, g[0]);
  auto &hare = s.build_actor<kmintapp::hare>(g, g[5]);
  hare.set_cow(&cow);

  ui::events::event_source event_source{};
  main_loop(s, window, [&](delta_time dt, loop_controls &ctl) {
    for (auto &e : event_source) {
      e.handle_quit([&](auto qe) {
        std::cout << "Bye!\n";
        ctl.quit = true;
      });
      e.handle_key_up([&](auto ke) {
        switch (ke.key) {
        case ui::events::key::p:
          ctl.pause = !ctl.pause;
          break;
        default:
          break;
        }
      });
    }
  });
  return 0;
}
*/
