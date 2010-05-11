/**
 * @file nodice/board.h
 * @brief Public interface of the nodice/board module.
 *
 * Copyright 2010 Stephen M. Webb  <stephen.webb@bregmasoft.ca>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of Version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef NODICE_BOARD_H
#define NODICE_BOARD_H 1

#include "nodice/object.h"
#include <vector>


namespace NoDice
{
	class Config;

	/**
	 * The playing surface.
	 */
	class Board
	{
	public:
		Board(const Config& config);

		const ObjectPtr& at(int x, int y) const;

		void update();
		void draw() const;

	private:
		typedef std::vector<ObjectPtr> ObjectBag;

		ObjectBag m_objects;
	};
} // namespace NoDice

#endif // NODICE_BOARD_H
