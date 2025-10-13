/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:39:26 by yanflous          #+#    #+#             */
/*   Updated: 2025/10/11 11:46:07 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"
# include <iostream>

Character::Character(): name("Unknown"), Backup_idx(0)
{
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
		this->Backup[i] = NULL;
	}
}

Character::Character(const std::string &name): name(name), Backup_idx(0)
{
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
		this->Backup[i] = NULL;
	}
} 

Character::Character(const Character &copy): name(copy.name), Backup_idx(copy.Backup_idx)
{
    for (int i = 0; i < 4; i++)
    {
        if (copy.inventory[i])
            this->inventory[i] = copy.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
	for (int i = 0; i < Backup_idx; i++)
	{
		if (copy.Backup[i])
			this->Backup[i] = copy.Backup[i]->clone();
		else
			this->Backup[i] = NULL;  
	}
}

Character &Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->Backup_idx = copy.Backup_idx;

		for (int i = 0; i < Backup_idx; i++)
		{
			if (this->Backup[i])
				delete this->Backup[i];
			this->Backup[i] = NULL;
		}

		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (copy.inventory[i])
				this->inventory[i] = copy.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	for (int i = 0; i < Backup_idx; i++)
	{
		if (this->Backup[i])
			delete this->Backup[i];
	}
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		this->Backup[Backup_idx] = this->inventory[idx];
		this->inventory[idx] = NULL;
		Backup_idx++;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
}
