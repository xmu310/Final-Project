#include"func.h"

void print_ascii(eAscii opt){
    if(opt==aStart){
        printf(" +--^----------,--------,-----,--------^-,                     | \n");
        printf(" | |||||||||   `--------'     |          O      ____    _ -- |    \\ \n");
        printf(" `+---------------------------^----------|      ____      -- |    /\n");
        printf("   `\\_,---------,---------,--------------'                    ~~~~\n");
        printf("     / XXXXXX /'|       /'\n");
        printf("    / XXXXXX /  `\\    /'    ██████╗  █████╗ ███╗   ██╗ ██████╗ ██╗\n");
        printf("   / XXXXXX /`-------'      ██╔══██╗██╔══██╗████╗  ██║██╔════╝ ██║\n");
        printf("  / XXXXXX /                ██████╔╝███████║██╔██╗ ██║██║  ███╗██║\n");
        printf(" / XXXXXX /                 ██╔══██╗██╔══██║██║╚██╗██║██║   ██║╚═╝\n");
        printf("(________(                  ██████╔╝██║  ██║██║ ╚████║╚██████╔╝██╗\n");
        printf(" `------'                   ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝\n\n");
    }
    else if(opt==aBomb){
        printf("        ,--.!,\n");
        printf("     __/   -*-\n");
        printf("   ,d08b.  '|`\n");
        printf("   0088MM\n");
        printf("   `9MMP' \n");
    }
    else if(opt==aExplode){
        printf("     _.-^^---....,,--       \n");
        printf(" _--                  --_  \n");
        printf("<                        >)\n");
        printf("|                         | \n");
        printf(" \\._                   _./  \n");
        printf("    ```--. . , ; .--'''       \n");
        printf("          | |   |         \n");
        printf("       .-=||  | |=-.   \n");
        printf("       `-=#$#&#$#=-'   \n");
        printf("          | ;  :|     \n");
        printf(" _____.,-##&$@##&#~,._____\n\n");
    }
    else if(opt==aJail){
        printf("  _________________________\n");
        printf("     ||   ||     ||   ||\n");
        printf("     ||   ||, , ,||   ||\n");
        printf("     ||  (||/|/(\\||/  ||\n");
        printf("     ||  ||| _'_`|||  ||\n");
        printf("     ||   || o o ||   ||\n");
        printf("     ||  (||  - `||)  ||\n");
        printf("     ||   ||  =  ||   ||\n");
        printf("     ||   ||\\___/||   ||\n");
        printf("     ||___||) , (||___||\n");
        printf("    /||---||-\\_/-||---||\\\n");
        printf("   / ||--_||_____||_--|| \\\n");
        printf("  (_(||)-|         |-(||)_)\n");
        printf("  _________________________\n");
    }
    else if(opt==aBeer){
        printf(".~~~~.\n");
        printf("i====i_\n");
        printf("|cccc|_)\n");
        printf("|cccc|\n");
        printf("`-==-'\n");
    }
    
}