#include "common.hpp"
#include <opencv2/cvv.hpp>
#include "cvv_types.hpp"

extern "C" {
	Result_void cvv_impl_debugDMatch_const__InputArrayX_vector_KeyPoint__const__InputArrayX_vector_KeyPoint__vector_DMatch__const_CallMetaDataX_const_charX_const_charX_bool(const cv::_InputArray* img1, std::vector<cv::KeyPoint>* keypoints1, const cv::_InputArray* img2, std::vector<cv::KeyPoint>* keypoints2, std::vector<cv::DMatch>* matches, const cvv::impl::CallMetaData* data, const char* description, const char* view, bool useTrainDescriptor) {
		try {
			cvv::impl::debugDMatch(*img1, *keypoints1, *img2, *keypoints2, *matches, *data, description, view, useTrainDescriptor);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cvv_impl_debugFilter_const__InputArrayX_const__InputArrayX_const_CallMetaDataX_const_charX_const_charX(const cv::_InputArray* original, const cv::_InputArray* result, const cvv::impl::CallMetaData* data, const char* description, const char* view) {
		try {
			cvv::impl::debugFilter(*original, *result, *data, description, view);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cvv_impl_finalShow() {
		try {
			cvv::impl::finalShow();
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cvv_impl_showImage_const__InputArrayX_const_CallMetaDataX_const_charX_const_charX(const cv::_InputArray* img, const cvv::impl::CallMetaData* data, const char* description, const char* view) {
		try {
			cvv::impl::showImage(*img, *data, description, view);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result<void*> cvv_impl_CallMetaData_file_const(const cvv::impl::CallMetaData* instance) {
		try {
			const char* ret = instance->file;
			return Ok(ocvrs_create_string(ret));
		} OCVRS_CATCH(Result<void*>)
	}
	
	Result<size_t> cvv_impl_CallMetaData_line_const(const cvv::impl::CallMetaData* instance) {
		try {
			size_t ret = instance->line;
			return Ok(ret);
		} OCVRS_CATCH(Result<size_t>)
	}
	
	Result<void*> cvv_impl_CallMetaData_function_const(const cvv::impl::CallMetaData* instance) {
		try {
			const char* ret = instance->function;
			return Ok(ocvrs_create_string(ret));
		} OCVRS_CATCH(Result<void*>)
	}
	
	Result<bool> cvv_impl_CallMetaData_isKnown_const(const cvv::impl::CallMetaData* instance) {
		try {
			bool ret = instance->isKnown;
			return Ok(ret);
		} OCVRS_CATCH(Result<bool>)
	}
	
	void cv_CallMetaData_delete(cvv::impl::CallMetaData* instance) {
		delete instance;
	}
	Result<cvv::impl::CallMetaData*> cvv_impl_CallMetaData_CallMetaData() {
		try {
			cvv::impl::CallMetaData* ret = new cvv::impl::CallMetaData();
			return Ok(ret);
		} OCVRS_CATCH(Result<cvv::impl::CallMetaData*>)
	}
	
	Result<cvv::impl::CallMetaData*> cvv_impl_CallMetaData_CallMetaData_const_charX_size_t_const_charX(const char* file, size_t line, const char* function) {
		try {
			cvv::impl::CallMetaData* ret = new cvv::impl::CallMetaData(file, line, function);
			return Ok(ret);
		} OCVRS_CATCH(Result<cvv::impl::CallMetaData*>)
	}
	
	Result<bool> cvv_impl_CallMetaData_operator_bool(cvv::impl::CallMetaData* instance) {
		try {
			bool ret = instance->operator bool();
			return Ok(ret);
		} OCVRS_CATCH(Result<bool>)
	}
	
}
