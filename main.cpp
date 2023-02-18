#include<iostream>
#include<string>

using namespace std;

int noEntity1 = 0;
int noEntity2 = 0;

float origHumanHealth = 50.0f;
float origZombieHealth = 20.0f;

float humanHealth = 50.0f;
float zombieHealth = 20.0f;
float humanDamage = 10.0f;
float zombieDamage = 7.0f;
//float humanRes = 5.0f;
//float zombieRes = 10.0f;

int humanDeaths = 0;
int ZombieDeaths = 0;

bool humanWon;
string wonMessage;


int main()
{

	cout << "*** Humans VS. Zombies Simulation ***\n\n";

	cout << "A human has " << humanHealth << " health and " << humanDamage << " attack damage" << endl;
	cout << "A zombie has " << zombieHealth << " health and " << zombieDamage << " attack damage.\n" << endl;

	cout << "Enter the no. of Humans: " << flush;

	cin >> noEntity1;
	cout << "Enter the no. of Zombies: " << flush;
	cin >> noEntity2;


	while (noEntity1 > 0 && noEntity2 > 0)
	{

		humanHealth = humanHealth - zombieDamage;
		zombieHealth = zombieHealth - humanDamage;

		//cout << "Human --> Zombie: " << humanDamage << endl;
		//cout << "Human Health: " << humanHealth << endl;
		//cout << "Zombie Health: " << zombieHealth << "\n" << endl;
		//cout << "Zombie --> Human: " << zombieDamage << endl;
		//cout << "Human Health: " << humanHealth << endl;
		//cout << "Zombie Health: " << zombieHealth << "\n" << endl;

		if (humanHealth <= 0)
		{
			noEntity1 = noEntity1 - 1;
			humanHealth = origHumanHealth;
			humanDeaths++;
			//cout << "Human Dies! Total: " << noHumans << endl;

		}

		if (zombieHealth <= 0)
		{
			noEntity2 = noEntity2 - 1;
			zombieHealth = origZombieHealth;
			ZombieDeaths++;
			//cout << "Zombie Dies! Total: " << noZombies << endl;

		}

	}

	if (noEntity1 <= 0 && noEntity2 > 0) { humanWon = false; wonMessage = "Zombies Won!"; }
	if (noEntity2 <= 0 && noEntity1 > 0) { humanWon = true; wonMessage = "Humans Won!"; }

	cout << "" << endl;

	if (humanWon == false)
	{
		cout << "Zombies Won!" << endl;
		cout << "Their are " << noEntity2 << " Zombies still alive. " << ZombieDeaths << " Zombies lost their lifes and " << humanDeaths << " Humans lost their lifes." << endl;
	}
	else
	{
		cout << "Humans Won!" << endl;
		cout << "Their are " << noEntity1 << " Humans still alive. " << humanDeaths << " Humans lost their lifes and " << ZombieDeaths << " Zombies lost their lifes." << endl;
	}

	system("PAUSE");

	return 0;
}