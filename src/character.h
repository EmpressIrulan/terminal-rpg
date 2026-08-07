#pragma once

// Thrown by Character::changeMaxHp when the change would drop max HP to
// zero or below.
struct InvalidStatChange {
    int attempted;
};

class Character{
    private:
        int strength;
        int dodge;
        int maxhp;
        int reason;
        int persuasion;
        int currentHp;
        int gold;

    public:
        Character();
        void dealDamage(int damage);
        void heal(int heal);
        void changeStrength(int change);
        void changeDodge(int change);
        void changeReason(int change);
        void changePersuasion(int change);
        void changeMaxHp(int change);
        void changeGold(int change);

        int getStrength();
        int getDodge();
        int getMaxhp();
        int getReason();
        int getPersuasion();
        int getCurrentHp();
        int getGold();

        bool checkAlive();
};