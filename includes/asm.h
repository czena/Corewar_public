
#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# define SIZE_BUF 4096

typedef struct		s_token
{
	char			*name;
	int				line;
	int				col;
	int				n_byte;
	int				byte_code;
	int				types_op;
}					t_token;

typedef struct		s_point
{
	int				line;
	int				col;
}					t_point;

int					add_tokens(t_dlist **lst, char *line);
int					syntax_analysis(const char *filename, t_dlist **lst);
int					skip_spaces(char **line);
int					skip_label(char **line);
int					is_label_char(char c);
int					create_token(t_dlist **lst, char *line, t_point *point,
					t_arg_type type);
int					check_instruction(t_dlist **lst, char **line,
					t_point *point);
int					check_label(t_dlist **lst, char **line, t_point *point);
int					check_direct_label(t_dlist **lst, char **line,
					t_point *point);
int					check_separator(t_dlist **lst, char **line,
					t_point *point);
int					check_registor(t_dlist **lst, char **line,
					t_point *point);
int					check_direct(t_dlist **lst, char **line, t_point *point);
int					check_comment(t_dlist **lst, char **line, t_point *point);
int					check_name(t_dlist **lst, char **line, t_point *point);
int					check_ind(t_dlist **lst, char **line, t_point *point);
int					check_ind_label(t_dlist **lst, char **line,
					t_point *point);
int					check_endl(t_dlist **lst, char **line, t_point *point);
int					check_op(t_dlist **lex);
void				delete_token(void *ptr);
int					lex_analysis(t_dlist *lex);
int					lex_check_begin(t_dlist **lex);
const t_op			*get_info(const char *cmd_name);
int					get_dir_size(const t_op *op);
char				*read_file(const char *filename);
int					error_at_token(t_dlist *lst);
int					find_str(void *s1, void *s2);
int					create_byte_code(t_dlist *lex, const char *filename);
int					init_labels(t_dlist *lex);
void				init_lab_op(t_dlist *lex);
void				print_short(short int sh_int_arg, const int fd,
					int *cur_byte);
void				print_int(int int_arg, const int fd, int *cur_byte);
void				print_char(char c, const int fd, int *cur_byte);
void				print_commands_byte(t_dlist *lex, const int fd);
int					find_str(void *s1, void *s2);

#endif
