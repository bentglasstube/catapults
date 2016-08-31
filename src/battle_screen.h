#pragma once

#include <memory>
#include <vector>

#include "boulder.h"
#include "catapult.h"
#include "clouds.h"
#include "map.h"

#include "framework/graphics.h"
#include "framework/input.h"
#include "framework/audio.h"
#include "framework/particle.h"
#include "framework/screen.h"
#include "framework/text.h"

class BattleScreen : public Screen {
  public:

    void init();
    bool update(Input& input, Audio& audio, unsigned int elapsed);
    void draw(Graphics& graphics) const;

    Screen* next_screen();

  private:

    enum class GameState { COUNTDOWN, FIGHT, WINNER };

    GameState state_;
    int p1score_, p2score_;
    int counter_;
    std::unique_ptr<Text> text_;

    std::vector<Catapult> players_;
    std::vector<Boulder> boulders_;
    std::vector<Particle> particles_;

    Map map_;
    Clouds clouds_;

    void launch_boulder(int x, int y, float angle);

    void add_dirt_particles(int x, int y, int n);
    void add_smoke_particles(int x, int y, int n);
    void reset_game();
};
