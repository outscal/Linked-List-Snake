#pragma once
class Player {
public:
    Player();  // Default constructor
    ~Player(); // Destructor

    void initialize(); // To be called when the object is created
    void update();     // To be called on every frame
    void render();     // To be called on every frame
};
