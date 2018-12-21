class velocity {
  public:
    double x,y;
    velocity(double x1=0,double y1=0) {
        x=x1;
        y=y1;
    }
    velocity multiply(double m) {
        return velocity(x*m,y*m);
    }
    velocity add(double a) {
        return velocity(x+a,y+a);
    }
    velocity add(velocity a) {
        return velocity(x+a.x,y+a.y);
    }
};
