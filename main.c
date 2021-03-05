#include "intarray.h"
#include "tools.h"
#include "jstr.h"

int			main(int argc, char** argv)
{
	jstr j = standard_empty_create_jstr();

	int i;
	for (i = 1; i < argc; i++)
	{
		jstr tmp = regstr_to_jstr(argv[i]);
		d_concat_jstr(j , tmp);
		destroy_jstr(tmp);
	}
	ext_debug_jstr(j);
	destroy_jstr(j);
	return (0);
}