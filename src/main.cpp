#include <iostream>
#include <vector>
#include <stdlib.h>

#include "character.hpp"
#include "attack.hpp"
#include "factory.hpp"
#include "battleOptions.hpp"
#include <stdlib.h> 

using namespace std;

int main(){
    //Warrior* warr1 = new Warrior(1, 1, 1, 1);
    //AttackWarrior* aWarrior = new AttackWarrior;
    //warr1->setAttack(aWarrior);
    

    //Warrior* warr2 = new Warrior(1, 1, 1, 1);

    //warr1->attackHit(warr2);
    
    //cout << warr2->getHealth() << endl;
    

    //delete warr1;
    //delete warr2;


    //Archer* arch1 = new Archer(1, 1, 1, 1);
    //AttackArcher* aArcher = new AttackArcher;
    //arch1->setAttack(aArcher);

    //Archer* arch2 = new Archer(1, 1, 1, 1);

    //arch1->attackHit(arch2);

    //delete arch1;
    //delete arch2;

    //ENEMIES

    //Dragon* drag = new Dragon(1, 1, 1, 1);
  //  if(drag->dodgeAttack() == true){
//	cout << "dodged" << endl;
    //}
  //  else if(drag->dodgeAttack() == false){
//	cout << "hit" << endl;
    //}

    //delete drag;

    //Ogre* og = new Ogre(1, 1, 1, 1);
    //delete og;

    //Slime* slim = new Slime(1, 1, 1, 1);
    //delete slim;

    //Skeleton* skel = new Skeleton(1, 1, 1, 1);
    //delete skel;

    //Spider* spid = new Spider(1, 1, 1, 1);
   // delete spid;

   // Zombies* zomb = new Zombies(1, 1, 1, 1);
   // delete zomb;

factory f; //factory object used to build user's character
string type; //string to identify type of character 1-warrior, 2-archer, 3-assassin, 4-mage
string userName; //string to keep track of the user defined character name
battleOptions battle; //battle options object to have access to all the battle options classes
string userChoice = ""; //keeps track of the choice user makes in battle
string giveUp = "bruh"; //indicates if the user has decided to give up
bool skipEnemyDamage = false; //indicates if the user should skip taking damage from enemy, used when player should not use their turn.

bool validType = false;
cout << "Welcome to PLACEHOLDER! Please enter a name for your character: ";
cin >> userName;

//write more preliminary dialogue for introduction to the story/dungeon

while(validType == false){
	cout << userName << ", please press the number of character you want to be, the options are warrior(1) , archer(2), assassin(3), or mage(4): ";
        cin >> type;

	system("clear"); //command to clear terminal so only the important text is on the screen		

	if(type != "1" && type != "2" && type != "3" && type != "4"){
		cout << endl  <<"Invalid option, please try again" << endl;
	}
	else{
		validType = true;
	}
}
	//creation of character if proper criteria is met
       	Character* player1 = f.createChar(type);
       	AttackStrat* aPlayer = f.createAttack(type);
       
	player1->setAttack(aPlayer);

	Character* slim = new Slime(1, 1, 1, 1);	
	AttackStrat* slimy = new AttackEnemy; 

//start of first battle against slime
while(slim->getHealth() > 0){
	

	cout << endl << userName << "'s Current health : " << player1->getHealth() << endl;
	battle.printOptions(type);	

	cin >> userChoice;	
	if(userChoice == "1"){ //attack option
		battle.attackSeq(type, player1, slim);		
	}
	else if (userChoice == "2"){ //heal option
		battle.healSeq(player1);	
	}
	else if (userChoice == "3"){ //give up option
		cout << endl <<"You have selected the give up option, are you sure you want to give up?" << endl << "press 1 to give up and 2 to return to battle" << endl;
		giveUp = "6";
		while(giveUp != "1" && giveUp != "2")
		cin >> giveUp;
	
		if(giveUp == "1"){
		 cout << endl << "opt 1" << endl;	
		}
		else if(giveUp == "2"){
			cout << endl << "opt 2" << endl;
			skipEnemyDamage = true;		
		}
		else if(giveUp != "1" && giveUp != "2"){
			cout << endl  << "Invalid Option please try again" << endl;
		}
	}
	else{
		cout << endl  <<"Invalid option, please try again" << endl;
	}
	
	if(skipEnemyDamage == false){
		cout << endl << "take Damage" << endl;
		//battle.enemyAttackSeq(type, player1, slim);
	}
	
	skipEnemyDamage = false;

	//system("clear");
}

cout << endl  << "You have defeated the slime" << endl;










    return 0;
}

