
/** \file    tracking_inf.h
 *  \brief   The interface for object tracking.
 *  \version 0.1
 *  \date    2016-07-26
 *  \email   da.li@cripac.ia.ac.cn
 *
 * Licensed under The MIT License [see LICENSE for details]
 */

#ifndef _TRACKING_H_
#define _TRACKING_H_

#include <string>

#include "basic_define.h"

/** \class ObjTacking
 *  \brief The implementation of object tracking:
 *         init(), doTrack(), destroy().
 */
class ObjTracking {
 public:
  ObjTracking() {
    handle = 0;
  }
  ~ObjTracking() {
    destroy();
  }

  /** \fn        init
   *  \brief     initialize the basic information of the input video and
   *             necessary parameters.
   *  \param[IN] w - width of the video frame.
   *  \param[IN] h - height of the video frame.
   *  \param[IN] chns_num - number of channels (eg. RGB, chns_num = 3).
   *  \param[IN] buffer - the data of configure file.
   *  \param[IN] buffer_len - length of the configure buffer.
   *  \return    Whether the function run successfully or not.
   */
  bool init(int w, int h, int chns_num, const char *buffer, int buffer_len);

  /** \fn         doTrack
   *  \brief      Start to track.
   *  \param[IN]  frame_data - rgb data of current video frame.
   *  \return     Whether the function run successfully or not.
   */
  bool doTrack(const unsigned char *frame_data);

  /**
   * \fn          getTrajs
   * \brief       To return the tracking results include the
   *              bounding boxes and rgb data.
   * \param[OUT]  trajs_num - the number of trajectories.
   * \return      A pointer points to trajectory data (see basic_define.h).
   *              It's not necessary to free the pointer, but you should
   *              assign NULL to it finally (see unittest/main.cpp).
   */
  Trajectory *getTrajs(int &trajs_num);

  /** \fn    destroy
   *  \brief Release recourses.
   */
  void destroy(void);

// Modified by da.li on 2016/11/9
 private:
  long handle;
// End

};  // ObjTracking

#endif  // _TRACKING_H_
