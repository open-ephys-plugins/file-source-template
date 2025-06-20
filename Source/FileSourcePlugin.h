/*
------------------------------------------------------------------

This file is part of the Open Ephys GUI
Copyright (C) 2022 Open Ephys

------------------------------------------------------------------

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef FILESOURCEPLUGIN_H_DEFINED
#define FILESOURCEPLUGIN_H_DEFINED

#include <FileSourceHeaders.h>

class FileSourcePlugin : public FileSource
{
public:
    /** The class constructor, used to initialize any members. */
    FileSourcePlugin();

    /** The class destructor, used to deallocate memory */
    ~FileSourcePlugin();

    // ------------------------------------------------------------
    //                  PURE VIRTUAL METHODS
    //        (must be implemented by all File Sources)
    // ------------------------------------------------------------

    /** Attempt to open the file, and return true if successful */
    bool open (File file) override;

    /** Fill the infoArray and eventInfoArray with the relevant information for all recordings*/
    void fillRecordInfo() override;

    /** Update the recording to be read in */
    void updateActiveRecord (int index) override;

    /** Seek to a specific sample number within the active recording */
    void seekTo (int64 sample) override;

    /** Read in nSamples of data */
    int readData (float* buffer, int nSamples) override;;

    /** Add info about events occurring within a sample number range */
    void processEventData (EventInfo& info, int64 startSample, int64 stopSample) override;
};

#endif