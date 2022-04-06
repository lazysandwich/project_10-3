#include <SFML/Graphics.hpp>

using namespace sf;

class PLAYER {
    public:
    float dx, dy;
    FloatRect rect;
    bool onGround;
    Sprite sprite;
    float currentFrame;
    PLAYER(Texture &image) {
        sprite.setTexture(image);
        rect = FloatRect(0, 0, 40, 50);
        dx = dy = 0;
        currentFrame = 0;
    }
    void update(float time) {
        rect.left += dx * time;
        if(!onGround) dy = dy + 0.0005 *time;
        rect.top += dy * time;
        
    }
}

int main() {
    RenderWindow window(VideoModo(200, 200), "Test!");
    CircleShape MyCircle(100.f);
    MyCircle.setFillColor(Color::Green);
    Texture t;
    t.loadFromFile("");
    float currentFrame = 0;
    Sprite s;
    s.setTexture(t);
    s.setTextureRect(IntRect(0, 244, 40, 50))
    s.setPosition(50, 100)
    
    Clock clock;
    
    while(window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
            if((Keyboard::isKeyPressed(Keyboard::Left))) {
                s.move(-0.1 *time, 0);
                 currentFrame += 0.005 *time;
                if(currentFrame > 6) currentFrame -= 6;
                s.setTextureRect(IntRect(40 *int(currentFrame) + 40, 244, -40, 50));
            }
            if((Keyboard::isKeyPressed(Keyboard::Right))) {
                s.move(0.1 *time, 0);
                currentFrame += 0.005 *time;
                if(currentFrame > 6) currentFrame -= 6;
                s.setTextureRect(IntRect(40 *int(currentFrame), 244, 40, 50));
            }
            if((Keyboard::isKeyPressed(Keyboard::Up))) {
                s.move(0.0 *time, 1);
            }
            if((Keyboard::isKeyPressed(Keyboard::Down))) {
                s.move(0.0*time, -1);
            }
            
        }
        window.clear(Color::White);
        window.draw(s);
        window.display();
    }
    return 0;
}
