#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    struct Horario
    {
        int horas;
        int minutos;
        int segundos;
    };

    Horario h1, h2, soma;

    cout << endl << "Informe o primeiro horario" << endl;

    do
    {
        cout << "Hora: ";
        cin >> h1.horas;
    } while (h1.horas < 0 || h1.horas > 23);

    do
    {
        cout << "Minutos: ";
        cin >> h1.minutos;
    } while (h1.minutos < 0 || h1.minutos > 59);

    do
    {
        cout << "Segundos: ";
        cin >> h1.segundos;
    } while (h1.segundos < 0 || h1.segundos > 59);

    cout << endl << "Informe o segundo horario" << endl;

    do
    {
        cout << "Hora: ";
        cin >> h2.horas;
    } while (h2.horas < 0 || h2.horas > 23);

    do
    {
        cout << "Minutos: ";
        cin >> h2.minutos;
    } while (h2.minutos < 0 || h2.minutos > 59);

    do
    {
        cout << "Segundos: ";
        cin >> h2.segundos;
    } while (h2.segundos < 0 || h2.segundos > 59);

    soma.segundos = h1.segundos + h2.segundos;
    soma.minutos = h1.minutos + h2.minutos + (soma.segundos / 60);
    soma.horas = h1.horas + h2.horas + (soma.minutos / 60);

    soma.horas = soma.horas % 24;
    soma.minutos = soma.minutos % 60;
    soma.segundos = soma.segundos % 60;

    cout << endl << "Horarios somados" << endl;
    cout << setfill('0') << setw(2) << soma.horas << ":"
         << setfill('0') << setw(2) << soma.minutos << ":"
         << setfill('0') << setw(2) << soma.segundos << endl;

    cout << endl;

    return 0;
}