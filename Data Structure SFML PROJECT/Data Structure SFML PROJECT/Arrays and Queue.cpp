#include <SFML/Graphics.hpp>
#include<string>
#include<string.h>
#include<conio.h>
#include<iostream>
#include <sstream>
using namespace std;
using namespace sf;
int s = 0;
int kj = 0;
int p = 0;
int tt = 0;
int arr2[100];
int arr3[100];
int x = 0, y = 0;
int jj = 0;
int ij = 0;
int front = -1, rear = -1;
sf::RenderWindow window(sf::VideoMode(800, 500), "Visualizer Array and Stack");
Text* text;
RectangleShape* box;
Text* text2;
RectangleShape* box2;
Font font;
void arr(int si)
{
	int a = 0;
	system("cls");
	string n1;
	window.clear(Color::White);
	font.loadFromFile("Arial.TTF");
	text = new Text[si];
	int x = 0, y = 0;
	int jj = 0;
	int ij = 0;
	for (int i = 0; i < si; i++)
	{

		text[i].setFont(font);
		text[i].setCharacterSize(18);
		text[i].setPosition(Vector2f(79 + y, 25));
		cout << "Enter The Value In Array : " << endl;
		cin >> n1;
		stringstream gk(n1);
		gk >> jj;

		arr2[ij] = jj;
		ij++;
		text[i].setString(n1);
		text[i].setFillColor(sf::Color::Blue);
		text[i].setStyle(Text::Bold);
		y = y + 71;

	}
	box = new RectangleShape[si];
	for (int i = 0; i < si; i++)
	{
		box[i].setSize(Vector2f(60, 60));
		box[i].setFillColor(Color::Cyan);
		box[i].setOutlineThickness(2);
		box[i].setPosition(Vector2f(60 + a, 10));
		a = a + 70;

	}
}

void dis(int index, int ssi)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}

	window.clear();

	for (int i = 0; i < ssi; i++)
	{
		if (i == index)
		{
			box[i].setFillColor(Color::Red);
			text[i].setFillColor(sf::Color::Green);
		}
		window.draw(box[i]);
	}
	for (int i = 0; i < ssi; i++)
	{
		window.draw(text[i]);
	}

	window.display();
}

void en_queue(int si)
{
	int a = 0;
	string n1;
	window.clear(Color::Green);
	font.loadFromFile("Arial.TTF");
	if (front == -1 && rear == -1)
	{
		front = rear = 0;
		cout << "Enter The Value : " << endl;
		cin >> n1;

		text2[rear].setFont(font);
		text2[rear].setCharacterSize(18);
		text2[rear].setPosition(Vector2f(79 + x, 25 + y));

		stringstream gk(n1);
		gk >> jj;
		arr3[ij] = jj;
		ij++;
		text2[rear].setString(n1);
		text2[rear].setFillColor(sf::Color::Blue);
		text2[rear].setStyle(Text::Bold);
		y = y + 71;

		box = new RectangleShape[si];
		for (int i = 0; i < si; i++)
		{
			box[front].setSize(Vector2f(60, 60));
			box[front].setFillColor(Color::White);
			box[front].setPosition(Vector2f(60, 10 + a));
			a = a + 70;
			return;
		}

	}
	else if (rear == si)
	{
		cout << "QUEUE IS FULL:\n";
		return;
	}
	else {
		rear++;
		cout << "Enter The Value : " << endl;
		cin >> n1;

		text2[rear].setFont(font);
		text2[rear].setCharacterSize(18);
		text2[rear].setPosition(Vector2f(79 + x, 25 + y));
		stringstream geek(n1);
		geek >> jj;
		arr3[ij] = jj;
		ij++;
		text2[rear].setString(n1);
		text2[rear].setFillColor(sf::Color::Black);
		text2[rear].setStyle(Text::Bold);
		y = y + 71;

		box = new RectangleShape[si];
		for (int i = 0; i < si; i++)
		{
			box[i].setSize(Vector2f(60, 60));
			box[i].setFillColor(Color::White);
			box[i].setPosition(Vector2f(60, 10 + a));
			a = a + 70;

		}
	}

}
void search(int n, int ssi)
{
	for (int i = 0; i < ssi; i++)
	{
		if (arr2[i] == n)
		{
			dis(i, ssi);
			box[i].setFillColor(Color::Cyan);
			text[i].setFillColor(sf::Color::Black);
		}

	}

}
void en_dis(int index, int ssi, bool a)
{


	if (a == true)
	{

		kj++;
	}

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}

	window.clear();
	for (int i = kj; i <= rear; i++)
	{
		if (index == i)
		{

			box[i].setFillColor(Color::Blue);
			text2[i].setFillColor(sf::Color::Green);
		}
		window.draw(box[i]);
	}
	for (int i = kj; i <= rear; i++)
	{
		window.draw(text2[i]);
	}
	window.display();
}
void de_search(int n, int ssi)
{

	for (int i = 0; i < ssi; i++)
	{

		if (arr3[i] == n)
		{

			en_dis(i, ssi, false);
			box[i].setFillColor(Color::White);
			text2[i].setFillColor(sf::Color::Black);
		}
		else {
			continue;
		}

	}

}



void de_queue(int ssi)
{

	bool aa = true;
	en_dis(100, ssi, aa);

}





int main()
{
	int si;
	cout << "ENTER THE SIZE FOR (ARRAY) and (QUEUE):\n";
	cin >> si;
	text2 = new Text[si]; 
	while (1)
	{
		int c;
		cout << "Please Press 1 for Insertion in an Array :\n";
		cout << "Please Press 2 for Display in an Array :\n";
		cout << "Please Press 3 for Searching in an Array :\n";
		cout << "Please Press 4 for En-queue in Queue :\n";
		cout << "Please Press 5 for De-queue in Queue :\n";
		cout << "Please Press 6 for Display in Queue :\n";
		cout << "Please Press 7 for Search in Queue   :\n";
		cout << "Please Press 8 for Exit   :\n";

		cin >> c;
		system("pause>0");
		system("cls");
		switch (c) {
		case 1:
		{

			p = si;
			arr(si);
			system("pause>0");
			system("cls");
			break;

		}
		case 2:
		{

			dis(100, si);
			system("pause>0");
			system("cls");
			break;

		}
		case 3:
		{

			cout << "ENTER THE DATA YOU WANT TO SEARCH:\n";
			int d;
			cin >> d;
			search(d, si);
			system("pause>0");
			system("cls");
			break;

		}
		case 4:
		{
			en_queue(si);
			system("pause>0");
			system("cls");
			break;
		}
		case 5:
		{

			de_queue(si);
			system("pause>0");
			system("cls");
			break;

		}
		case 6:
		{

			en_dis(100, si, false);
			system("pause>0");
			system("cls");
			break;

		}
		case 7:
		{

			cout << "ENTER THE DATA YOU WANT TO SEARCH:\n";
			int d;
			cin >> d;
			de_search(d, si);
			system("pause>0");
			system("cls");
			break;

		}

		case 8:
		{

			cout << "Thank You Exiting....";
			break;

		}

		}
	}

	system("pause");
	return 0;
}