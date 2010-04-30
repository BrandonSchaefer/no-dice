/**
 * @file gamestate.h
 * @brief Public interface of the gamestate module.
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
#ifndef GAMESTATE_H
#define GAMESTATE_H 1

#include <tr1/memory>


namespace NoDice
{
	class Video;

	/**
	 * An abstract base class for things implementing a stateful part of the game.
	 */
	class GameState
	{
	public:
		enum PointerAction
		{
			pointerUp,
			pointerDown,
			pointerDoubleDown
		};

	public:
		virtual ~GameState() = 0;

		virtual void pause();
		virtual void resume();

		virtual void pointerMove(int x, int y, int dx, int dy);
		virtual void pointerClick(int x, int y, PointerAction action);
		virtual void update() = 0;

		virtual void draw(Video& video) = 0;
	};

	typedef std::tr1::shared_ptr<GameState> GameStatePtr;

} // namespace NoDice

#endif // GAMESTATE_H