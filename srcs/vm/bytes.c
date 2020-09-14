/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bytes.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 19:22:32 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/14 15:44:49 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint32_t	rev_bytes_32(uint32_t value)
{
	return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 |
	(value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
}

/*
**	READ_4_BYTES
**	Reads 4 bytes of memory, using get_pos to keep reading within memory field
*/

int			read_4_bytes(uint8_t *mem, long pos)
{
	uint32_t	sum;
	uint32_t	parts[4];

	parts[0] = mem[get_pos(pos, 0)];
	parts[1] = mem[get_pos(pos, 1)];
	parts[2] = mem[get_pos(pos, 2)];
	parts[3] = mem[get_pos(pos, 3)];
	sum = parts[0] << 24;
	sum += parts[1] << 16;
	sum += parts[2] << 8;
	sum += parts[3];
	return (sum);
}

void		write_4_bytes(uint8_t *mem, long pos, int value)
{
	uint32_t parts[4];

	parts[0] = ((0xFFL << 24) & value) >> 24;
	parts[1] = ((0xFFL << 16) & value) >> 16;
	parts[2] = ((0xFFL << 8) & value) >> 8;
	parts[3] = ((0xFFL << 0) & value) >> 0;
	mem[get_pos(pos, 0)] = parts[0];
	mem[get_pos(pos, 1)] = parts[1];
	mem[get_pos(pos, 2)] = parts[2];
	mem[get_pos(pos, 3)] = parts[3];
}

int			read_2_bytes(uint8_t *mem, long pos)
{
	uint32_t	sum;
	uint32_t	parts[2];

	parts[0] = mem[get_pos(pos, 0)];
	parts[1] = mem[get_pos(pos, 1)];
	sum = parts[0] << 8;
	sum += parts[1];
	return (sum);
}

void		write_2_bytes(uint8_t *mem, long pos, int value)
{
	uint32_t parts[2];

	parts[0] = ((0xFFL << 8) & value) >> 8;
	parts[1] = ((0xFFL << 0) & value) >> 0;
	mem[get_pos(pos, 0)] = parts[0];
	mem[get_pos(pos, 1)] = parts[1];
}
