#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>

using namespace std;

#define GRIDSIZE 4
#define UP      0
#define DOWN    2
#define LEFT    3
#define RIGHT   1
#define MAX_SHOTS 3

/*
string to_string(int x)
{
    std::string out_string;
    std::stringstream ss;
    ss << x;
    return ss.str();
}
*/


class Position
{

    int x, y;

public:

    Position (int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Position() {}

    void moveRight()
    {
        if(x < 3) {
            x++;
        }

        else {
            cout << "This is a 4*4 Grid & you are at the rightmost of the grid. Remind!" << endl;
        }
    }

    void moveLeft()
    {
        if(x > 0) {
            x--;
        }

        else {
            cout << "This is a 4*4 Grid & you are at the leftmost of the grid. Remind!" << endl;
        }
    }

    void moveUp()
    {
        if (y < 3)
        {
            y++;
        }

        else {
            cout << "This is a 4*4 Grid & you are at the topmost of the grid. Remind!" << endl;
        }


    }

    void moveDown()
    {
        if(y > 0) {
            y--;
        }

         else {
            cout << "This is a 4*4 Grid & you are at the bottommost of the grid. Remind!" << endl;
        }
    }


    bool isAdjacent(Position p)
    {
        if( abs(x - p.getX()) == 1 && (y == p.getY()) ) {
            return true;
        }

        else if( abs(y - p.getY()) == 1 && (x == p.getX()) ) {
            return true;
        }


        return false;
    }

    bool isSamePoint(Position p)
    {
        if( x == p.getX() && y == p.getY() ) {
            return true;
        }

        return false;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }


};


class Wumpus
{

    bool killed;
    Position p;

public:

    Wumpus(int x, int y)
    {
        p = Position(x, y);
        killed = false;
    }

    Wumpus()   {
        srand(time(nullptr));
        int wumpus_x = rand() % GRIDSIZE;
        int wumpus_y = rand() % GRIDSIZE;

        p = Position(wumpus_x, wumpus_y);

        killed = false;

    }

    void kill()
    {
        killed = true;
    }

    Position getPosition()
    {
        return p;
    }

    void setPosition(Position pos) {
        p = pos;
    }

};

class Pit
{

    Position p;

public:

    Pit()
    {
        int pit_x = rand() % GRIDSIZE;
        int pit_y = rand() % GRIDSIZE;
        p = Position(pit_x , pit_y);
    }


    Pit(int x, int y)
    {
        p = Position(x, y);
    }


    Position getPosition()
    {
        return p;
    }

    void setPosition(Position pos) {
        p = pos;
    }

};


class Player
{

    int direction;
    int total_shots;
    bool killed;
    Position p;

public:

    Player()
    {
        total_shots = 0;
        p = Position(0,0);

        srand(time(nullptr));
        direction = rand() % GRIDSIZE;

        killed = false;
    }

    void turnLeft()
    {
        direction = (direction + 3) % 4;
    }

    void turnRight()
    {
        direction = (direction + 1) % 4;
    }

    void moveForward()
    {
        if (direction == UP)
        {
            p.moveUp();
        }
        else if (direction == DOWN)
        {
            p.moveDown();
        }
        else if (direction == LEFT)
        {
            p.moveLeft();
        }
        else if (direction == RIGHT)
        {
            p.moveRight();
        }
    }

    bool isAdjacent(Position pos)
    {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos)
    {
        return p.isSamePoint(pos);
    }

    void kill()
    {
        killed = true;
    }

    string getPositionInfo()
    {
        return "Player is now at " + to_string(p.getX()) + ", " + to_string(p.getY());
    }

    int getPlayerX() {
        return p.getX();
    }

    int getPlayerY() {
        return p.getY();
    }


    string getDirectionInfo()
    {
        string s;
        if (direction == UP) s = "up";
        if (direction == DOWN) s = "down";
        if (direction == LEFT) s = "left";
        if (direction == RIGHT) s = "right";
        return "Player is moving at direction: " + s;
    }

    int getTotalShots() {
        return total_shots;
    }

    void setTotalShots(int d) {
        total_shots = d;
    }

};



class WumpusWorld
{

private:

    Player player;
    Wumpus wumpus;
    Position gold_position;
    Pit pt;
    bool ended;

public:

    WumpusWorld()
    {
        srand(time(nullptr));

        int wumpus_x = rand() % GRIDSIZE;
        int wumpus_y = rand() % GRIDSIZE;
        int gold_x = rand() % GRIDSIZE;
        int gold_y = rand() % GRIDSIZE;
        int pit_x = rand() % GRIDSIZE;
        int pit_y = rand() % GRIDSIZE;

        wumpus.setPosition( Position(wumpus_x, wumpus_y));
        gold_position = Position(gold_x, gold_y);
        pt.setPosition( Position(pit_x, pit_y) );
        ended = false;

    }

    WumpusWorld(int wumpus_x, int wumpus_y)
    {
        wumpus.setPosition( Position(wumpus_x, wumpus_y) );

        int gold_x = rand() % GRIDSIZE;
        int gold_y = rand() % GRIDSIZE;
        int pit_x = rand() % GRIDSIZE;
        int pit_y = rand() % GRIDSIZE;

        gold_position = Position(gold_x, gold_y);
        pt.setPosition( Position(pit_x, pit_y) );

        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y)
    {
        wumpus.setPosition(Position(wumpus_x, wumpus_y));
        gold_position = Position(gold_x, gold_y);

        int pit_x = rand() % GRIDSIZE;
        int pit_y = rand() % GRIDSIZE;

        pt.setPosition( Position(pit_x, pit_y) );

        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y)
    {
        wumpus.setPosition(Position(wumpus_x, wumpus_y));
        gold_position = Position(gold_x, gold_y);
        pt.setPosition( Position(pit_x, pit_y) );

        ended = false;

    }

    void moveForward()
    {
        player.moveForward();
        return showGameState();
    }

    void turnLeft()
    {
        player.turnLeft();
        return showGameState();
    }

    void turnRight()
    {
        player.turnRight();
        return showGameState();
    }

    void shoot()
    {
        if(player.getTotalShots() == MAX_SHOTS) {
            cout << "Bullets are no longer available!" << endl;
            return;
        }

        int s = player.getTotalShots();
        s++;
        player.setTotalShots(s);

        if (  ( player.getPlayerX() < wumpus.getPosition().getX() ) && (player.getPlayerY() == wumpus.getPosition().getY() ) )
        {
            wumpus.kill();
            cout << "Congratulations! You killed the Wumpus!" << endl;
            wumpus.setPosition(Position(5,5));

        }

        else if( ( player.getPlayerY() < wumpus.getPosition().getY() ) && (player.getPlayerX() == wumpus.getPosition().getX() ) ) {
            wumpus.kill();
            cout << "Congratulations! You killed the Wumpus!" << endl;
            wumpus.setPosition(Position(5,5));
        }

        else
        {
            cout << "Missed the Wumpus!" << endl;
            if( (MAX_SHOTS - player.getTotalShots()) != 0 ) {
                cout << "You have only " << MAX_SHOTS - player.getTotalShots() << " shots available.Think twice before making a shoot!!! " << endl;
            }

            else {
                cout << "Bullets are no longer available!" << endl;
            }
        }

    }

    void showGameState()
    {
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;

        if (player.isAdjacent(wumpus.getPosition()))
        {
            cout << "stench!" << endl;
        }

        if (player.isAdjacent(pt.getPosition()))
        {
            cout << "Breeze!" << endl;
        }

        if (player.isSamePoint(wumpus.getPosition()))
        {
            cout << "Player was attacked and killed by the Wumpus!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(pt.getPosition()))
        {
            cout << "You fell into a pit!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(gold_position))
        {
            cout << "Got the gold!" << endl;
            cout << "Game ended, you won!" << endl;
            ended = true;
        }
    }

    bool isOver()
    {
        return ended;
    }

};


int main()
{
    int c;

    int wumpus_x , wumpus_y , gold_x , gold_y , pit_x , pit_y ;

    FILE *inputFile = fopen("wumpus.txt", "r");

    if (inputFile != NULL) {
        int numbers[6];

        for(int i=0; i<6; i++) {
            fscanf(inputFile, "%d", &numbers[i]);
        }

        fclose(inputFile);

        wumpus_x = numbers[0];
        wumpus_y = numbers[1];
        gold_x = numbers[2];
        gold_y = numbers[3];
        pit_x = numbers[4];
        pit_y = numbers[5];

    }

    else {
        printf("Failed to open the file.\n");
    }


    WumpusWorld w(wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);

    w.showGameState();
    while (!w.isOver())
    {
        cout << "1: move forward" << endl;
        cout << "2: Turn left" << endl;
        cout << "3: Turn right" << endl;
        cout << "4: Shoot" << endl;
        cin >> c;
        if (c == 1)
        {
            w.moveForward();
        }
        else if (c == 2)
        {
            w.turnLeft();
        }
        else if (c == 3)
        {
            w.turnRight();
        }
        else if (c == 4)
        {
            w.shoot();
        }

        else {
            cout << "Invalid Choice!" << endl;
        }
    }
    return 0;
}
