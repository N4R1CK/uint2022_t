
#include <lib/number.h>
#include <iostream>
// why we need iostream here if
// we have included it in 
// lib/number.h?


int main() {
    uint2022_t a = from_string("10972248137587377366511872502374418540148785271864664140224003976912394763519345894330351399072725587226569450675744223489916367725489295806448207436491340599228997401420012529071180395583868049283025082524719590383187907857816337980585517000782912424520905193151019179684280147612287372121298604103041024");
    uint2022_t b = from_string("10972248137587377366511872502374418540148785271864664140224003976912394763519345894330351399072725587226569450675744223489916367725489295806448207436491340599228997401420012529071180395583868049283025082524719590383187907857816337980585517000782912424520905193151019179684280147612287372121298604103041024");

    std::cout << a << '\n' << b << '\n' << (a + b) << '\n' << a * b << '\n';


    std::printf("Programm ended wock with code 0, time of work: %u msc\n", clock());
    return 0;
}
