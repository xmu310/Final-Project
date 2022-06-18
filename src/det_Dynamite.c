#include"func.h"

void det_Dynamite(){
    print_ascii(aBomb);
    printf("Dynamite determine:");
    sPile temp; // determine card
    temp.num=0;
    if(!get_last_card(&temp, &stock)){ // check stock 沒牌?
        shuffling();
        get_last_card(&temp, &stock);
    }
    sleep(1);
    fflush(stdout);
    printf("(%s,%s) %s\n",
            suit_nametxt[temp.card[0].suit],
            rank_nametxt[temp.card[0].rank],
            type_nametxt[temp.card[0].type]);
    if(temp.card[0].suit==Spade && (temp.card[0].rank>=2 && temp.card[0].rank<=9)){
        // explode <- spade 2~9
        print_ascii(aExplode);
	sleep(1);
        fflush(stdout);
        printf("Spade 2-9: Dynamite explodes.\nplayer%d -3 blood\n", PlayerNow+1);

        player[PlayerNow].blood -= 3; // -3 blood

        // discard dynamite
        int32_t card_index = -1;
        find_card_index(player[PlayerNow].equip, Dynamite, &card_index);
        get_card(&discard, &player[PlayerNow].equip, card_index);
        print_all_status(); // print_player_state after (-3 blood) & (discard dynamite)

        ask_Sid_Ketchum(PlayerNow);

        if(player[PlayerNow].blood <= 0){ // dying
            while(PlayerNow==PlayerHuman && have_card(player[PlayerNow].hand, Beer) && player[PlayerNow].blood<player[PlayerNow].maxblood){
                // playerHuman -> use beer?
		sleep(1);
	        fflush(stdout);
                printf("Do you want to use Beer and +1 blood? (y/n)");
                char opt[100]={0};
                scanf("%[^\n]",opt);
                if(opt[0]=='Y' || opt[0]=='y'){	
                    player[PlayerNow].blood += 1; // +1 blood

                    // discard beer
                    int32_t card_index = -1;
                    find_card_index(player[PlayerNow].hand, Beer, &card_index);
                    get_card(&discard, &player[PlayerNow].hand, card_index);

                    print_all_status();
                    
                    ask_Suzy_Lafayette(PlayerNow);
                }
                else if(opt[0]=='N' || opt[0]=='n'){
                    break;
                }
                else{
                    printf("Invalid input!\n");
                    continue;
                }
            }
            if(player[PlayerNow].blood <= 0){ // dead
		sleep(1);
		fflush(stdout);
                printf("player%d is dead.\n", PlayerNow+1);
                player_dead(PlayerNow);
                // return 2; // continue;
            }
        }
    }
    else{ // not explode
	int32_t next_player=PlayerNow;
	while(1){
		next_player=(next_player+1)%PlayerNum;
		if(player[next_player].alive)break;
	}
	sleep(1);
        printf("Dinamite pass to Player%d\n", next_player+1);
        int32_t card_index = -1;
        find_card_index(player[PlayerNow].equip, Dynamite, &card_index);
        get_card(&player[next_player].equip, &player[PlayerNow].equip, card_index);		
    }
    get_last_card(&discard, &temp); // discard determine card
    // return 1;
}
