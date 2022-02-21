
#include "menu.h"

int main(int argc, char *argv[], etatson *etatson)
{
    etat etat;
    menu(&etat, etatson);
    *etatson = NOTMUTE;
    return 1;
}
