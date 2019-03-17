/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2013/11/06 14:44:35 by zaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op op_tab[16] =
		{
				{
						.op_code = 0x01,
						.name = "live",
						.arg_codes = 0,
						.arg_num = 1,
						.arg_type = {T_DIR, 0, 0},
						.cycles_to_exec = 10,
						.t_dir_size_diff = 0,
						.description = "live",
						.change_carry = 0,
						.idx_mod = false,
						.f_ptr = &op_live
				},
				{
						.op_code = 0x02,
						.name = "ld",
						.arg_codes = 1,
						.arg_num = 2,
						.arg_type = {T_DIR | T_IND, T_REG, 0},
						.t_dir_size_diff = 0,
						.cycles_to_exec = 5,
						.change_carry = 1,
						.description = "load",
						.idx_mod = true,
						.f_ptr = &op_ld
				},
				{
						.op_code = 0x03,
						.name = "st",
						.arg_codes = 1,
						.arg_num = 2,
						.arg_type = {T_REG, T_IND | T_REG, 0},
						.t_dir_size_diff = 0,
						.cycles_to_exec = 5,
						.change_carry = 0,
						.description = "store",
						.idx_mod = true,
						.f_ptr = &op_st
				},
				{
						.op_code = 0x04,
						.name = "add",
						.arg_codes = 1,
						.arg_num = 3,
						.arg_type = {T_REG, T_REG, T_REG},
						.t_dir_size_diff = 0,
						.cycles_to_exec = 10,
						.change_carry = 1,
						.description = "add",
						.idx_mod = false,
						.f_ptr = &op_add
				},
				{
						.op_code = 0x05,
						.name = "sub",
						.arg_codes = 1,
						.arg_num = 3,
						.arg_type = {T_REG, T_REG, T_REG},
						.t_dir_size_diff = 0,
						.cycles_to_exec = 10,
						.change_carry = 1,
						.description = "subtraction",
						.idx_mod = false,
						.f_ptr = &op_sub
				},
				{
						.op_code = 0x06,
						.name = "and",
						.arg_codes = 1,
						.arg_num = 3,
						.arg_type = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
						.t_dir_size_diff = 0,
						.cycles_to_exec = 6,
						.change_carry = 1,
						.description = "bitwise AND (&)",
						.idx_mod = true,
						.f_ptr = &op_and
				},
				{
						.op_code = 0x07,
						.name = "or",
						.arg_codes = 1,
						.arg_num = 3,
						.arg_type = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
						.t_dir_size_diff = 0,
						.cycles_to_exec = 6,
						.change_carry = 1,
						.idx_mod = true,
						.description = "bitwise OR (|)",
						.f_ptr = &op_or
				},
				{
						.op_code = 0x08,
						.name = "xor",
						.arg_codes = 1,
						.arg_num = 3,
						.arg_type = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
						.t_dir_size_diff = 0,
						.cycles_to_exec = 6,
						.change_carry = 1,
						.idx_mod = true,
						.description = "bitwise XOR (^)",
						.f_ptr = &op_xor
				},
				{
						.op_code = 0x09,
						.name = "zjmp",
						.arg_codes = 0,
						.arg_num = 1,
						.arg_type = {T_DIR, 0, 0},
						.t_dir_size_diff = 1,
						.cycles_to_exec = 20,
						.change_carry = 0,
						.description = "jump if carry non-zero",
						.idx_mod = false,
						.f_ptr = &op_zjmp
				},
				{
						.op_code = 0x0a,
						.name = "ldi",
						.arg_codes = 1,
						.arg_num = 3,
						.arg_type = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
						.t_dir_size_diff = 1,
						.cycles_to_exec = 25,
						.change_carry = 0,
						.description = "load index",
						.idx_mod = true,
						.f_ptr = &op_ldi
				},
				{
						.op_code = 0x0b,
						.name = "sti",
						.arg_codes = 1,
						.arg_num = 3,
						.arg_type = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
						.t_dir_size_diff = 1,
						.cycles_to_exec = 25,
						.change_carry = 0,
						.description = "store index",
						.idx_mod = true,
						.f_ptr = &op_sti
				},
				{
						.op_code = 0x0c,
						.name = "fork",
						.arg_codes = 0,
						.arg_num = 1,
						.arg_type = {T_DIR, 0, 0},
						.t_dir_size_diff = 1,
						.cycles_to_exec = 800,
						.change_carry = 0,
						.description = "fork",
						.idx_mod = true,
						.f_ptr = &op_fork
				},
				{
						.op_code = 0x0d,
						.name = "lld",
						.arg_codes = 1,
						.arg_num = 2,
						.arg_type = {T_DIR | T_IND, T_REG},
						.t_dir_size_diff = 0,
						.cycles_to_exec = 10,
						.change_carry = 1,
						.description = "long load",
						.idx_mod = false,
						.f_ptr = &op_lld
				},
				{
						.op_code = 0x0e,
						.name = "lldi",
						.arg_codes = 1,
						.arg_num = 3,
						.arg_type = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
						.t_dir_size_diff = 1,
						.cycles_to_exec = 50,
						.change_carry = 1,
						.description = "long load index",
						.idx_mod = true,
						.f_ptr = &op_lldi
				},
				{
						.op_code = 0x0f,
						.name = "lfork",
						.arg_codes = 0,
						.arg_num = 1,
						.arg_type = {T_DIR, 0, 0},
						.t_dir_size_diff = 1,
						.cycles_to_exec = 1000,
						.change_carry = 0,
						.description = "long fork",
						.idx_mod = false,
						.f_ptr = &op_lfork
				},
				{
						.op_code = 0x10,
						.name = "aff",
						.arg_codes = 1,
						.arg_num = 1,
						.arg_type = {T_REG, 0, 0},
						.t_dir_size_diff = 0,
						.cycles_to_exec = 2,
						.change_carry = 0,
						.description = "aff",
						.idx_mod = false,
						.f_ptr = &op_aff
				},
		};
