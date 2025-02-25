/*
  Copyright (C) 2001-2004 Stephane Magnenat & Luc-Olivier de Charrière
  for any question or comment contact us at <stephane at magnenat dot net> or <NuageBleu at gmail dot com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef __SECTOR_H
#define __SECTOR_H

#include <list>

class Map;
class Game;
class Bullet;
struct BulletExplosion;
class Explosion;
class Team;

#ifndef YOG_SERVER_ONLY
struct UnitDeathAnimation
{
	UnitDeathAnimation(int x, int y, Team *team);
	int x, y, ticksLeft;
	Team *team;
};
#endif  // !YOG_SERVER_ONLY

// a 16x16 piece of Map
class Sector
{
public:
	Sector() {}
	Sector(Game *);
	virtual ~Sector(void);
	// !This call is needed to use the Sector!
	void setGame(Game *game);

	void free(void);

	std::list<Bullet *> bullets;
	std::list<BulletExplosion *> explosions;
#ifndef YOG_SERVER_ONLY
	std::list<UnitDeathAnimation *> deathAnimations;
#endif  // !YOG_SERVER_ONLY

	void save(GAGCore::OutputStream *stream);
	bool load(GAGCore::InputStream *stream, Game *game, Sint32 versionMinor);

	// Server needs only load and save from this class.
#ifndef YOG_SERVER_ONLY
	void step(void);
#endif  // !YOG_SERVER_ONLY
private:
	Map *map;
	Game *game;
};

#endif
 
