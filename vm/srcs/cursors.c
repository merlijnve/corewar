#include "../inc/vm.h";
#include "../libs/libft/libft.h";

/**
 * Definitely not complete yet, but it's a start.
 */

int create_cursors(t_arena *arena_s)
{
    int i;
    i = 0;
    t_cursor *parent;
    t_cursor *curr;

    parent = NULL;
    curr = NULL;

    if (!arena_s->player_count)
    {
        return (-1);
    }

    parent = ft_memalloc(sizeof(t_cursor));

    /** Check for memory issues */
    if (!parent)
    {
        return (-1);
    }

    curr = parent;

    while (i < arena_s->player_count - 1)
    {
        curr->next = ft_memalloc(sizeof(t_cursor));
        curr = curr->next;
        i++;
    }

    return (1);
}