#include <SFML/Graphics.hpp>

using namespace sf;

int ground = 150;

float offsetX = 0, offsetY = 0;

const H = 12;
const W = 40;

String TileMap[H] = {
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    "B                                B     B",
    "B                                B     B",
    "B                                B     B",
    "B                                B     B",
    "B         0000                BBBB     B",
    "B                                B     B",
    "BBB                              B     B",
    "B             BB                 BB    B",
    "B             BB                       B",
    "B    B        BB         BB            B",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
}

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
        Collision(0);
        if(!onGround) dy = dy + 0.0005 *time;
        rect.top += dy * time;
        onGround = false;
        Collision(1);
        currentFrame += 0.005 * time;
        if(currentFrame > 6)
            currentFrame -= 6;
        if(dx > 0)
            sprite.setTextureRect(IntRect(40 * int(currentFrame), 244, 40, 50));
        if(dx < 0)
            sprite.setTextureRect(IntRect(40 * int(currentFrame) + 40, 244, -40, 50));
        spriter.setPosition(rect.left - offsetX, rect.top - offsetY);
        dx = 0;
    }
    void Collision(int dir) {
        for(int i = rect.top/32; i < (rect.top + rect.height)/32; i++) {
            for(int j = rect.left/32; j < (rect.left + rect.width)/32; j++) {
                if(TileMap[i][j] == 'B') {
                    if(dy > 0 && dir == 1) {
                        rect.top = i * 32 - rect.hieght;
                        dy = 0;
                        onGround = true;
                    }
                    if(dx < 0 && dir == 1) {
                        rect.top = i * 32 + 32;
                        dy = 0;
                    }
                    if(dy > 0 && dir == 0)
                        rect.left = j * 32 - rect.width;
                    if(dx < 0 && dir == 0) 
                        rect.left = j * 32 + 32;
            }
            if(TileMap[i][j] == '0') {
                TileMap[i][j] = ' ';
            }
        }
    }
}

int main() {
    RenderWindow window(VideoModo(200, 200), "Test!");
    CircleShape MyCircle(100.f);
    MyCircle.setFillColor(Color::Green);
    Texture t;
    t.loadFromFile("");
    float currentFrame = 0;
    PLAYER p(t);
    
    Clock clock;
    
    while(window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
        }
        if((Keyboard::isKeyPressed(Keyboard::Left))) {
            p.dx = -0.1;
        }
        if((Keyboard::isKeyPressed(Keyboard::Right))) {
            p.dx = 0.1;
        }
        if((Keyboard::isKeyPressed(Keyboard::Up))) {
            if(p.onGround) {
                p.dy = - 0.4;
                p.onGround = false;
            }
        }
        offsetX = p.rect.left - 600/2;
        offsetY = p.rect.top - 400/2;
        window.clear(Color::White);
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(TileMap[i][j] == 'B')
                    rectangle.setFillColor(Color::Black);
                if(TileMap[i][j] == '0')
                    rectangle.setFillColor(Colore::Green);
                if(TileMap[i][j] == ' ')
                    continue;
                rectangle.setPosition(j * 32 - offsetX, i * 32 - offsetY);
                window.draw(rectangle);
            }
        }
        window.draw(p.sprite);
        window.display();
    }
    return 0;
}
