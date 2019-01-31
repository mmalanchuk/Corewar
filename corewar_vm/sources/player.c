#include "corewar_vm.h"

//TODO choose one way to push players

void	push_front_player(t_champ **lst, t_champ *player)
{
	if (!lst || !player)
		return;
	if (*lst)
		player->next = *lst;
	*lst = player;
}

void	push_back_player(t_champ **lst, t_champ *player)
{
	t_champ *temp;

	if (!lst || !player)
		return ;
	if (*lst == NULL)
		*lst = player;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = player;
	}
}

t_champ *new_player()
{
	t_champ *new;

	new = (t_champ *)malloc(sizeof(t_champ));
	new->name = NULL;
	new->comment = NULL;
	new->code_size = 0;
	new->code = 0;
	new->id = -1;
	new->next = NULL;
	new->last_live_cycles = -1;
	new->lives = 0;
	return (new);
}

char *parse_player_name(t_file file)
{
	char *name;
	ssize_t bytes_read;

	lseek(file.fd, 4, SEEK_SET);
	if (!(name = ft_strnew(PROG_NAME_LENGTH)))
		throw_error(MEM_ALLOC_ERR, file.name);
	if ((bytes_read = read(file.fd, name, PROG_NAME_LENGTH)) != PROG_NAME_LENGTH)
		throw_error(bytes_read == -1 ? READ_ERROR : INCOMPLETE_PLAYER, file.name);
	return (name);
}

char *parse_player_comment(t_file file)
{
	char *comment;
	ssize_t bytes_read;

	if (!(comment = ft_strnew(COMMENT_LENGTH)))
		throw_error(MEM_ALLOC_ERR, file.name);
	if ((bytes_read = read(file.fd, comment, COMMENT_LENGTH)) != COMMENT_LENGTH)
		throw_error(bytes_read == -1 ? READ_ERROR : INCOMPLETE_PLAYER, file.name);
	return (comment);
}

uint8_t *parse_code(t_file file, size_t code_size)
{
	uint8_t	*code;
	ssize_t			bytes_read;
	uint8_t last;

	if (!(code = (unsigned char *)ft_memalloc(sizeof(unsigned char) * code_size + 1)))
		throw_error(MEM_ALLOC_ERR, file.name);
	if ((bytes_read = read(file.fd, code, code_size)) != code_size)
		throw_error(bytes_read == -1 ? READ_ERROR : INCOMPLETE_PLAYER, file.name);
	if ((read(file.fd, &last, 1)) != 0)
		throw_error(END_ERR, file.name);
	return (code);
}

void parse_player(t_env *vm, char *filename, t_champ **lst, int *id)
{
	t_file	file;
	t_champ *player;

	if (vm->players_num + 1 > MAX_PLAYERS)
		throw_error(ERR_MANY_PLAYERS, file.name);
	file.name = filename;
	if ((file.open = (file.fd = open(file.name, O_RDONLY)) != -1) == false)
		throw_error(CANT_READ, file.name);
	if (!valid_header(file))
		throw_error(INVALID_HEADER, file.name);
	player = new_player();
	player->name = parse_player_name(file);
	if (read_uint32(file) != 0)
		throw_error(NO_NULL, file.name);
	if ((player->code_size = read_uint32(file)) > CHAMP_MAX_SIZE)
		throw_error(CODE_SIZE_ERR, file.name);
	player->comment = parse_player_comment(file);
	if (read_uint32(file) != 0)
		throw_error(NO_NULL, file.name);
	player->code = parse_code(file, player->code_size);
	player->id = *id;
	*id = -1;
	push_back_player(lst, player);
	vm->players_num++;
	close(file.fd);
}
