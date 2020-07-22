/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/01 19:24:35 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/07/08 21:26:23 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../inc/vm.h"

/*
**  TODO
**  - lexical analysis
**	- calculate zjmps and stuff
**  - write to .cor file
*/

void arena_loop(t_arena *arena_s)
{
    arena_s->cylces_count = 0;
    arena_s->cycles_to_die = CYCLE_TO_DIE;

    while (arena_s->check_count < arena_s->cycles_to_die)
    {
        // Do something with cursors   
        arena_s->cylces_count++;
    }
}

void start(void)
{
    int ret;
    t_arena arena_s;

    ret = 0;
    ft_bzero(&arena_s, sizeof(arena_s));

    ret = create_cursors(&arena_s);

    if (ret <= 0)
    {
        /** Something went wrong here */
        return;
    }
    
    // STart

    arena_loop(&arena_s);
}

int main(int argc, char **argv)
{

    ft_bzero(&asm_s, sizeof(asm_s));
    input_fd = check_args(argc, argv, &asm_s);
    // FOR OPENING OF NEW FILE WITH CORRECT RIGHTS
    //output_fd = open("test.cor", O_CREAT | O_RDWR, 0600);
    //close(fd);
    close(input_fd);
    return (0);
}