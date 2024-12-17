do{
                scanf("%d\n", &i);
                switch (i)
                {
                case 1:
                    if(map[x][y]->monster1->isAlive==false){
                        printf("The creature is dead.");
                        correctChc=false;
                        break;
                    }
                    takeDamageM(map[x][y]->monster1, attackP(&player));
                    break;
                case 2:
                    if(map[x][y]->monster2->isAlive==false){
                        printf("The creature is dead.");
                        correctChc=false;
                        break;
                    }
                    takeDamageM(map[x][y]->monster2, attackP(&player));
                    break;
                case 3:
                    if(map[x][y]->monster3->isAlive==false){
                        printf("The creature is dead.");
                        correctChc=false;
                        break;
                    }
                    takeDamageM(map[x][y]->monster3, attackP(&player));
                    break;
                default:
                    break;
                }
            }while(correctChc==false);