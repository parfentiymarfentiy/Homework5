class Player;
class Team {
public:
    void addPlayer(Player* player) {
        players.push_back(player);
    }
private:
    vector<Player*> players;
};

class Player {
public:
    string name;
};