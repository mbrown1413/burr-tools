
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
#include "undomanager.h"

#include "../tools/xml.h"

#include <sstream>

UndoManager_c::UndoManager_c(void) {
    currentState = -1;
    savedState = -1;
}
UndoManager_c::~UndoManager_c(void) { }

void UndoManager_c::loadNew(puzzle_c * puzzle) {
  currentState = -1;
  savedState = -1;
  states.resize(0);

  recordState(puzzle);
  markSaved();
}

void UndoManager_c::recordState(puzzle_c * puzzle) {
  std::ostringstream stateString;
  xmlWriter_c xml(stateString);
  puzzle->save(xml);

  if (savedState > currentState) {
    savedState = -1;
  }

  states.resize(currentState+1);
  states.push_back(stateString.str());
  currentState = states.size()-1;
}

puzzle_c * UndoManager_c::undo(void) {
  if (currentState <= 0) { return NULL; }
  currentState--;

  std::istringstream stateString(states[currentState]);
  xmlParser_c xml(stateString);
  return new puzzle_c(xml);
}

puzzle_c * UndoManager_c::redo(void) {
  if ((unsigned int) currentState >= states.size()-1) { return NULL; }
  currentState++;

  std::istringstream stateString(states[currentState]);
  xmlParser_c xml(stateString);
  return new puzzle_c(xml);
}

void UndoManager_c::markSaved(void) {
  savedState = currentState;
}

bool UndoManager_c::isChanged(void) {
  return currentState != -1 && currentState != savedState;
}