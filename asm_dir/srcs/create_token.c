#include "asm.h"
#include "libft.h"

int		create_token(t_dlist **lst, char *line, t_point *point,
		t_arg_type type)
{
	t_token		*token;

	if (!(token = (t_token *)malloc(sizeof(*token))))
	{
		free(line);
		return (-1);
	}
	token->name = line;
	token->line = point->line;
	token->col = point->col;
	token->n_byte = 0;
	token->byte_code = 0;
	token->types_op = 0;
	if (ft_dlist_push_link(lst, token, type) == NULL)
	{
		free(line);
		free(token);
		return (-1);
	}
	return (0);
}

void	delete_token(void *ptr)
{
	t_token *token;

	token = (t_token *)ptr;
	free(token->name);
	free(token);
}
