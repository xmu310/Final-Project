#include"func.h"

// if still in jail, return 1
// else if get out of jail, return 2 
int32_t det_Jail(){

        int32_t card_index = -1;
        find_card_index(player[PlayerNow].equip, Jail, &card_index);
	get_card(&discard, &player[PlayerNow].equip, card_index);
    printf("Jail determine:");
    sPile temp; // determine card
    temp.num=0;
    if(!get_last_card(&temp, &stock)){ // check stock 沒牌?
        shuffling();
        get_last_card(&temp, &stock);
    }
    printf("(%s,%s) %s\n",
            suit_nametxt[temp.card[0].suit],
            rank_nametxt[temp.card[0].rank],
            type_nametxt[temp.card[0].type]);
    
    if(temp.card[0].suit==Heart){ // heart -> get out of jail, return 2
        printf("Heart: player%d escapes from the Jail!\n", PlayerNow);
        // discard jail
        print_all_status();
        get_last_card(&discard, &temp); // discard determine card
        return 2;
    }else{ // still in jail, return 1
        print_ascii(aJail);
        printf("player%d is still in the Jail :(\n", PlayerNow);
        get_last_card(&discard, &temp); // discard determine card
        return 1;
    }    
}
