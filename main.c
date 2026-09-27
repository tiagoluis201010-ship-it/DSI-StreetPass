#include <nds.h>
#include <dswifi9.h>
#include <stdio.h>

// Função para tocar a vinheta de notificação estilo StreetPass
void playStreetPassChime() {
    soundPlayPSG(FREQ_C5, 127, 64);
    swiDelay(300000);
    soundPlayPSG(FREQ_G5, 127, 64);
}

int main(void) {
    // Inicializa a tela em modo de texto básico
    consoleDemoInit();

    printf("=================================\n");
    printf("     DSi STREETPASS PLAZA        \n");
    printf("=================================\n\n");
    printf("Pressione (A) para procurar...\n");

    while (pmMainLoop()) {
        scanKeys();
        u32 keys = keysDown();

        if (keys & KEY_A) {
            printf("\nProcurando StreetPass via Wi-Fi...\n");
            
            // Tenta ativar a pilha de Wi-Fi do DSi
            if (Wifi_InitDefault(WIFIMODE_DHCP)) {
                printf("\n---------------------------------\n");
                printf("    STREETPASS ENCONTRADO!       \n");
                printf("---------------------------------\n");
                printf("Visitante : Mii_Luigi\n");
                printf("Mensagem  : Viva o DSi!\n");
                printf("Origem    : Portugal\n");
                playStreetPassChime();
            } else {
                printf("\nErro ao conectar ao Wi-Fi.\nVerifique as definicoes da consola.\n");
            }
        }

        swiWaitForVBlank();
    }

    return 0;
}
