class Character{
    private:
        int strength;
        int dodge;
        int maxhp;
        int reason;
        int persuasion;
        int currentHp;

    public:
        Character();
        void dealDamage(int damage);
        void heal(int heal);
        void changeStrength(int change);
        void changeDoge(int change);
        void changeReason(int change);
        void changePersuasion(int change);
        void changeMaxHp(int change);
        bool checkAlive();

        int getStrength();
        int getDodge();
        int getMaxhp();
        int getReason();
        int getPersuasion();
        int getCurrentHp();
};