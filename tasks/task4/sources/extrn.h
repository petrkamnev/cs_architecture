extern "C"
{
    double getSpecCount(char* input, char* spec);
}
char* spec = "!#$%^&*()_-+=.,/?";
double getCharacteristicF(const char* input, double size) {
    return getSpecCount(const_cast<char*>(input), spec) / size;
}