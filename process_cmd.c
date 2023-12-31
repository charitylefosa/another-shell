#include "shell.h"

/**
*process_cmd- process the command and execute the corresponding actions
*@argv: array of strings where argv[0] is the command*
*Return: 0 if successful
*	1 if otherwise
*/
int process_cmd(char **argv)
{
	int num_arg = num_args(argv);

	if (_strcmp(argv[0], "cd") == 0)
	{
		if (num_arg >= 1)
		{
			cd(argv[1]);
			return (0);
		}
	}
	if (_strcmp(argv[0], "env") == 0)
	{
		_env();
		return (0);
	}
	if (_strcmp(argv[0], "setenv") == 0)
	{
		if (num_arg == 3)
		{
			_setenv(argv[1], argv[2]);
		return (0);
		}
	}
	if (_strcmp(argv[0], "unsetenv") == 0)
	{
		if (num_arg == 2)
		{
			_unsetenv(argv[1]);
			return (0);
		}
	}
	return (1);
}


/**
*_perrore- exit error for string or negatives
*@err: name of shell
*@count: number of command
*@c: command name
*@arg: command argument
*/
void _perrore(char *err, int count, char *c, char *arg)
{
	_print(err);
	_print(": ");
	_pnumber(count);
	_print(": ");
	_print(c);
	_print(": Illegal number: ");
	_print(arg);
	_print("\n");
}
