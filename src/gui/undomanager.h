/* BurrTools
 *
 * BurrTools is the legal property of its developers, whose
 * names are listed in the COPYRIGHT file, which is included
 * within the source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
#ifndef __UNDO_MANAGER_H__
#define __UNDO_MANAGER_H__

#include "../lib/puzzle.h"

#include <string>

/**
 * Manages saving and loading states for undo and redo.
 */
class UndoManager_c {

public:

  UndoManager_c(void);
  ~UndoManager_c(void);

  /**
   * Starts a new set of undo history. Called when a new puzzle is loaded or created.
   */
  void loadNew(puzzle_c * puzzle);

  /**
   * Saves the current state of the puzzle for undo.
   */
  void recordState(puzzle_c * puzzle);

  /**
   * Returns the puzzle from the previous state in the undo history, and sets that
   * state as current. Returns NULL if there is nothing to undo.
   */
  puzzle_c * undo();

  /**
   * Returns the puzzle from the next state in the undo history, and sets that state
   * as current. Returns NULL if there is nothing to redo.
   */
  puzzle_c * redo();

  /**
   * Returns true if there is something to undo.
   */
  bool canUndo(void);

  /**
   * Returns true if there is something to redo.
   */
  bool canRedo(void);

  /**
   * Marks the current state as saved to disk, so isChanged() will return false.
   */
  void markSaved(void);

  /**
   * Returns true if the currently saved state is not saved to disk.
   */
  bool isChanged(void);

private:

  std::vector<std::string> states;
  int currentState;
  int savedState;

};

#endif
