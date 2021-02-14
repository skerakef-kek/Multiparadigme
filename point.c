#include <stdlib.h>
#include <stdio.h>

typedef struct _point*	point;
typedef struct _point	s_point;

struct _point {
	float size;
	float* data;
};

void	debug_point(point p)
{
	int i;

	printf("[ ");
	for (i = 0; i < p->size - 1; i++)
		printf("%f,", p->data[i]);
	printf ("%f ]\n", p->data[i]);

	printf ("size est egal a %f:\n", p->size);
}

s_point	create_point(int size)
{
	s_point p;
	
	p.data = malloc (sizeof(float) * size);
	for (int i = 0; i < size; i++)
		p.data[i] = 0;
	p.size = size;
	return (p);
}

/*point	create_dyn_point(float x, float y)
{
	point p = malloc (sizeof (s_point));
	p->x = x;
	p->y = y;

	return (p);
}*/

void	f(s_point p, int index, int val)
{
	p.size = 5.0;
	p.data[index] = val;
}

int		main()
{
	s_point p = create_point(7);

	debug_point(&p);

	f(p, 4, 12.00);

	debug_point(&p);

	free (p.data);
	return (0);
}