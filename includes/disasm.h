/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:17:54 by nharra            #+#    #+#             */
/*   Updated: 2019/11/19 11:18:01 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_H
# define DISASM_H

# include "libft.h"
# include "op.h"

typedef struct		s_buf
{
	char			*buf;
	unsigned		i;
	unsigned		size;
}					t_buf;

typedef struct		s_token
{
	char			ch_op;
	short int		sh_op;
	int				int_op;
	int				dir_size;
}					t_token;

int					read_arg(const int fd, void *arg, unsigned size);
const t_op			*get_info_id(char id_op);
int					get_dir_size(const t_op *op);
int					error(const char *str);
int					new_op(t_dlist **lex, int type, int *num, const t_op *op);
int					create_token(t_buf *buf, t_dlist **lex);
int					create_tokens(t_dlist **lex, const char *filename,
					t_header *header);
int					create_file(t_dlist *lex, const char *filename,
					t_header *header);
int					read_ch(t_buf *buf, t_dlist **lex, int type);
int					read_short(t_buf *buf, t_dlist **lex, int type);
int					read_int(t_buf *buf, t_dlist **lex, int type);
int					read_dir(t_buf *buf, int dir_size, t_dlist **lex, int type);

#endif
