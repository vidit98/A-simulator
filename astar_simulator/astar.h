#ifndef ASTAR_H
#define ASTAR_H

#include "obstacles.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>


using namespace std;
using namespace Eigen;

struct node
{
	node *parent;
	Vector2f position;
	float g = 0;
	float h = 0;
	float f = 0;
	int flag = 1;

};

class ASTAR
{
	public:
		ASTAR();
		void initialize();
		void update_costs(node *q);
		float distance(Vector2f &p, Vector2f &q);
		void update_open(node *a);
		void get_neighbour(node *q);
		void explore();
		void show_open();
		void show_neighbour();
		void get_path();
		void setStepSize(int step);
		bool reached;
		int step_size;
		node *start;
		Obstacles *obstacles;
		Vector2f startPos, endPos , currentPos;
		vector<node *> open;// ascending order wrt f cost
		vector<node *> closed;
		vector<node *> neighbour;
		vector<node *> path;
		vector<node *> old_path;


};
#endif

