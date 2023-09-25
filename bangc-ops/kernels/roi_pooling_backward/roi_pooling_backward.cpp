/*************************************************************************
 * Copyright (C) [2023] by Cambricon, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *************************************************************************/
#include "kernels/kernel_wrapper/wrapper.h"

mluOpStatus_t MLUOP_WIN_API
mluOpRoiPoolingBackward(mluOpHandle_t handle,
                        mluOpPoolingMode_t pooling_mode,
                        const mluOpTensorDescriptor_t grads_desc,
                        const void *grads,
                        const mluOpTensorDescriptor_t rois_desc,
                        const void *rois,
                        const mluOpTensorDescriptor_t argmax_desc,
                        const int *argmax,
                        const float spatial_scale,
                        const mluOpTensorDescriptor_t grads_image_desc,
                        void *grads_image) {
  RoiPoolingBackwardWrapper wrapper;
  mluOpStatus_t ret = wrapper.invoke(handle, pooling_mode, grads_desc, grads,
                                rois_desc, rois, argmax_desc, argmax,
                                spatial_scale, grads_image_desc, grads_image);
  return ret;
}
