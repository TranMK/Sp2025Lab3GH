class Movie: protected Show{
    protected:
        double rating;
    public:
        bool set_rating(double rating);
        double get_rating(return rating);
        void Play() override;
        void Details();
}