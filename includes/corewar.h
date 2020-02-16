
#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <ncurses.h>

typedef struct		s_aff
{
	int		n;
	char	c;
}					t_aff;

typedef struct		s_player
{
	int		connect;
	int		n;
	char	*file;
	char	*name;
	char	*comment;
	char	*code;
	int		champ_size;
	int		start_pos;
	int		last_live;
	int		cur_live;
	int		prev_live;
}					t_player;

typedef struct		s_param
{
	int			last;
	long		n_cycle;
	long		n_live;
	long		cycles_to_die;
	long		n_cycles_to_die;
	long		n_check;
	t_dlist		*aff;
	int			n_players;
	int			aff_flag;
	int			dump_flag;
	int			visual_flag;
	t_player	*plr;
}					t_param;

typedef struct		s_cursor
{
	long			id;
	int				carry;
	long			last_live;
	long			remained_op;
	int				position;
	int				byte_to_next;
	int				op_code;
	int				reg[REG_NUMBER];
	int				creator;
	struct s_cursor	*next;
	struct s_cursor	*prev;
}					t_cursor;

typedef struct		s_vis
{
	int play;
	int speed;
}					t_vis;

int					check_input(char **input, int n,
								t_player *plr, t_param *param);
int					check_flags(t_param *param, char **input, int *i, int n);

int					print_errors(int n, char *str, char *str2);

void				players_init(t_player *plr);
int					players_id(t_player *plr);
void				players_delete(t_player *plr);

int					check_file(t_player *plr);
int					check_code(int fd, t_player *plr, char *str);

int					arena_init(t_player *plr, t_param *param);

void				print_arena(char **arena, t_cursor *cursor,
								t_param *param, t_vis *vis);
void				printf_cursors(t_cursor *cursor);
int					check_null(char *buffer);

void				new_param(t_param *param);
void				init_param(t_param *param, t_player *plr, t_player *first);

int					cursor_create(t_cursor **cursor, t_player *plr);
int					cursor_create_empty(t_cursor **cursor);
int					cursors_init(t_cursor **cursor, t_player *plr);
void				cursor_delete(t_cursor **cursor);
void				cursor_delete_all(t_cursor **cursor);
void				cursor_to_bgn(t_cursor **cursor);
int					cursors_count(t_cursor *cursor);

int					start_battle(t_player *plr, char **arena, t_param *param);
void				check_change_position(char **arena, t_cursor *cursor);
void				check_cursor_is_ready(char **arena, t_cursor **cursor,
										t_param *param);

t_op				*get_op(int n);

int					check_flag_n(t_player *plr, char **input, int *i, int n);
int					check_num(char *str, int *num);

void				check_operations(t_cursor *cursor, char **arena,
									t_param *param);
int					change_operation(t_cursor *cursor, char **arena);
int					check_types(char **arena, int n_op,
								int size_dir, int start);
int					start_check_types(char **arena, t_cursor *cursor,
										int dir_size);

void				operation_live(t_cursor *cursor, t_param *param,
									char **arena);
void				operation_ld(t_cursor *cursor, char **arena);
void				operation_st(t_cursor *cursor, char **arena,
								t_param *param);
void				operation_add(t_cursor *cursor, char **arena);
void				operation_sub(t_cursor *cursor, char **arena);
void				operation_and(t_cursor *cursor, char **arena);
void				operation_or(t_cursor *cursor, char **arena);
void				operation_xor(t_cursor *cursor, char **arena);
void				operation_zjmp(t_cursor *cursor, char **arena);
void				operation_ldi(t_cursor *cursor, char **arena);
void				operation_sti(t_cursor *cursor, char **arena,
									t_param *param);
void				operation_fork(t_cursor *cursor, char **arena);
void				operation_lld(t_cursor *cursor, char **arena);
void				operation_lldi(t_cursor *cursor, char **arena);
void				operation_lfork(t_cursor *cursor, char **arena);
void				operation_aff(t_cursor *cursor,
									char **arena, t_param *param);

int					reg_read(t_cursor *cursor, char **arena);
int					dir_read(t_cursor *cursor, char **arena, int dir_size);
int					ind_read(t_cursor *cursor, char **arena);
int					init_type(char *type, t_cursor *cursor, char **arena,
								int dir_size);

int					get_t_dir(char **arena, int start, int dir_size);
int					get_t_ind(char **arena, int start);
int					get_t_reg(char **arena, int start);
void				set_dir_arena(char **arena, int start, int x);
void				set_dir_owner(t_cursor *cursor, char **arena,
									int start, t_param *param);
int					get_bin_num(char type, int n);

void				print_introduction(t_player *plr, t_param *param);
void				print_winners(t_player *plr, t_param *param);
void				print_dump(char **arena);

void				print_border_horizontal(void);
void				print_status(t_player *player, t_vis *vis,
								t_param *param, t_cursor *cursor);
void				check_gecth(t_vis *vis);
void				print_players(t_player *plr, t_param *param);
void				create_colors(void);
void				print_winner(t_player *plr, t_param *param);
void				print_speed(t_vis *vis);
void				print_cur_period(t_param *param);
void				print_last_period(t_param *param);
void				save_cur_live(t_player *plr);

#endif
