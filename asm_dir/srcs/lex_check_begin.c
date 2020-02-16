#include "asm.h"
#include "libft.h"

static void		skip_endl(t_dlist **lex)
{
	while (*lex && (*lex)->tag == T_ENDL)
		*lex = (*lex)->next;
}

static int		lex_check_name(t_dlist *el)
{
	if (ft_strlen(((t_token *)el->content)->name) > PROG_NAME_LENGTH)
	{
		ft_printf("Champion name too long (Max length %d)", PROG_NAME_LENGTH);
		return (0);
	}
	else
		return (1);
}

static int		lex_check_comment(t_dlist *el)
{
	if (ft_strlen(((t_token *)el->content)->name) > COMMENT_LENGTH)
	{
		ft_printf("Champion comment too long (Max length %d)", COMMENT_LENGTH);
		return (0);
	}
	else
		return (1);
}

static int		check_t_com(t_dlist **lex)
{
	if (lex_check_comment(*lex) == 0)
		return (-2);
	*lex = (*lex)->next;
	skip_endl(lex);
	if (*lex && (*lex)->tag == T_NAME && (*lex)->prev->tag != T_COM)
	{
		if (lex_check_name(*lex) == 0)
			return (-2);
		*lex = (*lex)->next;
		return (0);
	}
	else
		return (-1);
}

int				lex_check_begin(t_dlist **lex)
{
	if (lex == NULL || *lex == NULL)
		return (-1);
	skip_endl(lex);
	if ((*lex)->tag == T_NAME)
	{
		if (lex_check_name(*lex) == 0)
			return (-2);
		(*lex) = (*lex)->next;
		skip_endl(lex);
		if (*lex && (*lex)->tag == T_COM && (*lex)->prev->tag != T_NAME)
		{
			if (lex_check_comment(*lex) == 0)
				return (-2);
			*lex = (*lex)->next;
			return (0);
		}
		else
			return (-1);
	}
	else if ((*lex)->tag == T_COM)
		return (check_t_com(lex));
	return (-1);
}
