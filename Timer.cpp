#include "Timer.h"
#include "DetectarRosto.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

Timer::Timer() {
}

void Timer::displayClock(){ // A arrumar
        /**system("clear"); // Limpa a tela
    
        cout << "         TIMER         \n";
        cout << " --------------------------\n";
        cout << seconds << endl;**/
    };
    
    void Timer::timer() {
        while (true) {
            displayClock();
            sleep(1); // Delay proposital
            
            seconds--; // Faz o decremento dos segundos até zerar
    
            if (seconds == -1) { // Mostra o ultimo segundo como zero
            pontuacao.salvarPontuacaoEmArquivo();
            break;
            }
        }
    };

