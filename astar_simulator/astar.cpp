#include "astar.h"
 

ASTAR::ASTAR()
{
	obstacles = new Obstacles;
	start = new node;
	start->parent = NULL;
	
    endPos.x() = END_POS_X;
    endPos.y() = END_POS_Y;
    currentPos.x() = START_POS_X;
    currentPos.y() = START_POS_Y;
	open.push_back(start);
	closed.push_back(start);
	step_size = 3;
}

void ASTAR::initialize()
{
	start = new node;
	start->parent = NULL;
	start->position = currentPos;
	open.push_back(start);
	closed.push_back(start);
}

void ASTAR::update_costs(node *q)
{

	q->g = q->parent->g +  distance(q->parent->position , q->position );
	q->h = distance(q->position , endPos);
	q->f = 4*q->h  + ((q->g));
}

float ASTAR::distance(Vector2f &p, Vector2f &q)
{
	Vector2f v = p - q;
    return sqrt(powf(v.x(), 2) + powf(v.y(), 2));
}

void ASTAR::update_open(node *a)
{

	vector< node* >::iterator it;
	it = open.begin();

	for (int k = 0; k < open.size(); ++k)
	{
		if(a->f >= open[k]->f)
		{
			open.insert(it + k , a);
			break;
		}
		if(k == open.size() - 1)
		{
			open.push_back(a);
		}

	}
	if(open.size() == 0)
	{
		open.push_back(a);
	}
}

void ASTAR::get_neighbour(node *q)
{
	neighbour.clear();
	for (int i = -step_size; i < (step_size + 1); i+=step_size)
	{
		for (int j = -step_size;  j< (step_size + 1); j+=step_size)
		{
			if(i == 0 && j == 0)
			{
				continue;
			}
			Vector2f t;
			t.x() = i;
			t.y() = j;
		
			t = q->position + t;
			
			int f = 0;
			for (int k = 0; k < closed.size(); ++k)
			{
				if(closed[k]->position == t)
				{
					f = 1;
					break;
				}
			}

			if(!f)
			{
				node* nbr;
				nbr = new node;
				nbr->parent = q;
				nbr->position = t;

				neighbour.push_back(nbr);
			}
		}
	}
}

void ASTAR::explore()
{
	for (int i = 0 ; i < neighbour.size() ; i++)
	{
		
			
		update_costs(neighbour[i]);

		int flag = 0;
		for (int k = 0; k < open.size(); ++k)
		{
			//printf("%s %d %d\n","111111" , open.size() , k );
			Vector2f v = open[k]->position;
			//printf("%s %d %d\n","22222" , open.size() , k );
			if(open[k]->position == neighbour[i]->position)
			{

				if(open[k]->f > neighbour[i]->f)
				{
					open.erase(open.begin() + k);
				}
				else
				{
					flag = 1;
				}
				break;
				
			}
		}

		if(flag != 1)
		{
			update_open(neighbour[i]);
		}
		
		if(neighbour[i]->position == endPos)
		{
			reached = true;
			break;
		}

		
	}
}

void ASTAR::show_open()
{
	for (int i = 0; i < open.size(); ++i)
	{
		printf("%f %f %f %f %f\n",open[i]->position.x() , open[i]->position.y() , open[i]->f , open[i]->g , open[i]->h );
	}
}
void ASTAR::show_neighbour()
{
	for (int i = 0; i < neighbour.size(); ++i)
	{
		node *a = neighbour[i];
		update_costs(neighbour[i]);
		printf("%f %f %f %f %f\n", a->position.x() , a->position.y() , a->f , a->g , a->h);
	}
}

void ASTAR::get_path()
{
	node *p;
    p = open[open.size() - 1];
    Vector2f pos = p->position;
    
    while(pos != currentPos)
    {   
        path.push_back(p);
        pos = p->position;
        p = p->parent;
    }
}
void ASTAR::setStepSize(int step)
{
    step_size = step;
}

