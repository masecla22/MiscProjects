class bit {
  public:
    bool state;
    void negate() {
        state =!state;
    }
    bit(bool state1) {
        state = state1;
    }
    bit operator!(){
        state = !state;
    }

};
std::ostream &operator<<(std::ostream &os, bit what){
        return os<<what.state;
}
