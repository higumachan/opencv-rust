#include "sfm.hpp"
#include "sfm_types.hpp"

extern "C" {
	Result_void cv_sfm_KRtFromProjection_const__InputArrayX_const__OutputArrayX_const__OutputArrayX_const__OutputArrayX(const cv::_InputArray* P, const cv::_OutputArray* K, const cv::_OutputArray* R, const cv::_OutputArray* t) {
		try {
			cv::sfm::KRtFromProjection(*P, *K, *R, *t);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_applyTransformationToPoints_const__InputArrayX_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* points, const cv::_InputArray* T, const cv::_OutputArray* transformed_points) {
		try {
			cv::sfm::applyTransformationToPoints(*points, *T, *transformed_points);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_computeOrientation_const__InputArrayX_const__InputArrayX_const__OutputArrayX_const__OutputArrayX_double(const cv::_InputArray* x1, const cv::_InputArray* x2, const cv::_OutputArray* R, const cv::_OutputArray* t, double s) {
		try {
			cv::sfm::computeOrientation(*x1, *x2, *R, *t, s);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result<double> cv_sfm_depth_const__InputArrayX_const__InputArrayX_const__InputArrayX(const cv::_InputArray* R, const cv::_InputArray* t, const cv::_InputArray* X) {
		try {
			double ret = cv::sfm::depth(*R, *t, *X);
			return Ok(ret);
		} OCVRS_CATCH(Result<double>)
	}
	
	Result_void cv_sfm_essentialFromFundamental_const__InputArrayX_const__InputArrayX_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* F, const cv::_InputArray* K1, const cv::_InputArray* K2, const cv::_OutputArray* E) {
		try {
			cv::sfm::essentialFromFundamental(*F, *K1, *K2, *E);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_essentialFromRt_const__InputArrayX_const__InputArrayX_const__InputArrayX_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* R1, const cv::_InputArray* t1, const cv::_InputArray* R2, const cv::_InputArray* t2, const cv::_OutputArray* E) {
		try {
			cv::sfm::essentialFromRt(*R1, *t1, *R2, *t2, *E);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_euclideanToHomogeneous_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* src, const cv::_OutputArray* dst) {
		try {
			cv::sfm::euclideanToHomogeneous(*src, *dst);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result<double> cv_sfm_fundamentalFromCorrespondences7PointRobust_const__InputArrayX_const__InputArrayX_double_const__OutputArrayX_const__OutputArrayX_double(const cv::_InputArray* x1, const cv::_InputArray* x2, double max_error, const cv::_OutputArray* F, const cv::_OutputArray* inliers, double outliers_probability) {
		try {
			double ret = cv::sfm::fundamentalFromCorrespondences7PointRobust(*x1, *x2, max_error, *F, *inliers, outliers_probability);
			return Ok(ret);
		} OCVRS_CATCH(Result<double>)
	}
	
	Result<double> cv_sfm_fundamentalFromCorrespondences8PointRobust_const__InputArrayX_const__InputArrayX_double_const__OutputArrayX_const__OutputArrayX_double(const cv::_InputArray* x1, const cv::_InputArray* x2, double max_error, const cv::_OutputArray* F, const cv::_OutputArray* inliers, double outliers_probability) {
		try {
			double ret = cv::sfm::fundamentalFromCorrespondences8PointRobust(*x1, *x2, max_error, *F, *inliers, outliers_probability);
			return Ok(ret);
		} OCVRS_CATCH(Result<double>)
	}
	
	Result_void cv_sfm_fundamentalFromEssential_const__InputArrayX_const__InputArrayX_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* E, const cv::_InputArray* K1, const cv::_InputArray* K2, const cv::_OutputArray* F) {
		try {
			cv::sfm::fundamentalFromEssential(*E, *K1, *K2, *F);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_fundamentalFromProjections_const__InputArrayX_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* P1, const cv::_InputArray* P2, const cv::_OutputArray* F) {
		try {
			cv::sfm::fundamentalFromProjections(*P1, *P2, *F);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_homogeneousToEuclidean_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* src, const cv::_OutputArray* dst) {
		try {
			cv::sfm::homogeneousToEuclidean(*src, *dst);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_importReconstruction_const_StringX_const__OutputArrayX_const__OutputArrayX_const__OutputArrayX_const__OutputArrayX_int(const char* file, const cv::_OutputArray* Rs, const cv::_OutputArray* Ts, const cv::_OutputArray* Ks, const cv::_OutputArray* points3d, int file_format) {
		try {
			cv::sfm::importReconstruction(cv::String(file), *Rs, *Ts, *Ks, *points3d, file_format);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_isotropicPreconditionerFromPoints_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* points, const cv::_OutputArray* T) {
		try {
			cv::sfm::isotropicPreconditionerFromPoints(*points, *T);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_meanAndVarianceAlongRows_const__InputArrayX_const__OutputArrayX_const__OutputArrayX(const cv::_InputArray* A, const cv::_OutputArray* mean, const cv::_OutputArray* variance) {
		try {
			cv::sfm::meanAndVarianceAlongRows(*A, *mean, *variance);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result<int> cv_sfm_motionFromEssentialChooseSolution_const__InputArrayX_const__InputArrayX_const__InputArrayX_const__InputArrayX_const__InputArrayX_const__InputArrayX(const cv::_InputArray* Rs, const cv::_InputArray* ts, const cv::_InputArray* K1, const cv::_InputArray* x1, const cv::_InputArray* K2, const cv::_InputArray* x2) {
		try {
			int ret = cv::sfm::motionFromEssentialChooseSolution(*Rs, *ts, *K1, *x1, *K2, *x2);
			return Ok(ret);
		} OCVRS_CATCH(Result<int>)
	}
	
	Result_void cv_sfm_motionFromEssential_const__InputArrayX_const__OutputArrayX_const__OutputArrayX(const cv::_InputArray* E, const cv::_OutputArray* Rs, const cv::_OutputArray* ts) {
		try {
			cv::sfm::motionFromEssential(*E, *Rs, *ts);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_normalizeFundamental_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* F, const cv::_OutputArray* F_normalized) {
		try {
			cv::sfm::normalizeFundamental(*F, *F_normalized);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_normalizeIsotropicPoints_const__InputArrayX_const__OutputArrayX_const__OutputArrayX(const cv::_InputArray* points, const cv::_OutputArray* normalized_points, const cv::_OutputArray* T) {
		try {
			cv::sfm::normalizeIsotropicPoints(*points, *normalized_points, *T);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_normalizePoints_const__InputArrayX_const__OutputArrayX_const__OutputArrayX(const cv::_InputArray* points, const cv::_OutputArray* normalized_points, const cv::_OutputArray* T) {
		try {
			cv::sfm::normalizePoints(*points, *normalized_points, *T);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_normalizedEightPointSolver_const__InputArrayX_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* x1, const cv::_InputArray* x2, const cv::_OutputArray* F) {
		try {
			cv::sfm::normalizedEightPointSolver(*x1, *x2, *F);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_preconditionerFromPoints_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* points, const cv::_OutputArray* T) {
		try {
			cv::sfm::preconditionerFromPoints(*points, *T);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_projectionFromKRt_const__InputArrayX_const__InputArrayX_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* K, const cv::_InputArray* R, const cv::_InputArray* t, const cv::_OutputArray* P) {
		try {
			cv::sfm::projectionFromKRt(*K, *R, *t, *P);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_projectionsFromFundamental_const__InputArrayX_const__OutputArrayX_const__OutputArrayX(const cv::_InputArray* F, const cv::_OutputArray* P1, const cv::_OutputArray* P2) {
		try {
			cv::sfm::projectionsFromFundamental(*F, *P1, *P2);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_reconstruct_const__InputArrayX_const__OutputArrayX_const__OutputArrayX_const__InputOutputArrayX_bool(const cv::_InputArray* points2d, const cv::_OutputArray* Ps, const cv::_OutputArray* points3d, const cv::_InputOutputArray* K, bool is_projective) {
		try {
			cv::sfm::reconstruct(*points2d, *Ps, *points3d, *K, is_projective);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_reconstruct_const__InputArrayX_const__OutputArrayX_const__OutputArrayX_const__InputOutputArrayX_const__OutputArrayX_bool(const cv::_InputArray* points2d, const cv::_OutputArray* Rs, const cv::_OutputArray* Ts, const cv::_InputOutputArray* K, const cv::_OutputArray* points3d, bool is_projective) {
		try {
			cv::sfm::reconstruct(*points2d, *Rs, *Ts, *K, *points3d, is_projective);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_reconstruct_vector_String__const__OutputArrayX_const__OutputArrayX_const__InputOutputArrayX_bool(const std::vector<cv::String>* images, const cv::_OutputArray* Ps, const cv::_OutputArray* points3d, const cv::_InputOutputArray* K, bool is_projective) {
		try {
			cv::sfm::reconstruct(*images, *Ps, *points3d, *K, is_projective);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_reconstruct_vector_String__const__OutputArrayX_const__OutputArrayX_const__InputOutputArrayX_const__OutputArrayX_bool(const std::vector<cv::String>* images, const cv::_OutputArray* Rs, const cv::_OutputArray* Ts, const cv::_InputOutputArray* K, const cv::_OutputArray* points3d, bool is_projective) {
		try {
			cv::sfm::reconstruct(*images, *Rs, *Ts, *K, *points3d, is_projective);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_relativeCameraMotion_const__InputArrayX_const__InputArrayX_const__InputArrayX_const__InputArrayX_const__OutputArrayX_const__OutputArrayX(const cv::_InputArray* R1, const cv::_InputArray* t1, const cv::_InputArray* R2, const cv::_InputArray* t2, const cv::_OutputArray* R, const cv::_OutputArray* t) {
		try {
			cv::sfm::relativeCameraMotion(*R1, *t1, *R2, *t2, *R, *t);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result<cv::Mat*> cv_sfm_skew_const__InputArrayX(const cv::_InputArray* x) {
		try {
			cv::Mat ret = cv::sfm::skew(*x);
			return Ok(new cv::Mat(ret));
		} OCVRS_CATCH(Result<cv::Mat*>)
	}
	
	Result_void cv_sfm_triangulatePoints_const__InputArrayX_const__InputArrayX_const__OutputArrayX(const cv::_InputArray* points2d, const cv::_InputArray* projection_matrices, const cv::_OutputArray* points3d) {
		try {
			cv::sfm::triangulatePoints(*points2d, *projection_matrices, *points3d);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_BaseSFM_run_const__InputArrayX(cv::sfm::BaseSFM* instance, const cv::_InputArray* points2d) {
		try {
			instance->run(*points2d);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_BaseSFM_run_const__InputArrayX_const__InputOutputArrayX_const__OutputArrayX_const__OutputArrayX_const__OutputArrayX(cv::sfm::BaseSFM* instance, const cv::_InputArray* points2d, const cv::_InputOutputArray* K, const cv::_OutputArray* Rs, const cv::_OutputArray* Ts, const cv::_OutputArray* points3d) {
		try {
			instance->run(*points2d, *K, *Rs, *Ts, *points3d);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_BaseSFM_run_const_vector_String_X(cv::sfm::BaseSFM* instance, const std::vector<cv::String>* images) {
		try {
			instance->run(*images);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_BaseSFM_run_const_vector_String_X_const__InputOutputArrayX_const__OutputArrayX_const__OutputArrayX_const__OutputArrayX(cv::sfm::BaseSFM* instance, const std::vector<cv::String>* images, const cv::_InputOutputArray* K, const cv::_OutputArray* Rs, const cv::_OutputArray* Ts, const cv::_OutputArray* points3d) {
		try {
			instance->run(*images, *K, *Rs, *Ts, *points3d);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result<double> cv_sfm_BaseSFM_getError_const(const cv::sfm::BaseSFM* instance) {
		try {
			double ret = instance->getError();
			return Ok(ret);
		} OCVRS_CATCH(Result<double>)
	}
	
	Result_void cv_sfm_BaseSFM_getPoints_const__OutputArrayX(cv::sfm::BaseSFM* instance, const cv::_OutputArray* points3d) {
		try {
			instance->getPoints(*points3d);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result<cv::Mat*> cv_sfm_BaseSFM_getIntrinsics_const(const cv::sfm::BaseSFM* instance) {
		try {
			cv::Mat ret = instance->getIntrinsics();
			return Ok(new cv::Mat(ret));
		} OCVRS_CATCH(Result<cv::Mat*>)
	}
	
	Result_void cv_sfm_BaseSFM_getCameras_const__OutputArrayX_const__OutputArrayX(cv::sfm::BaseSFM* instance, const cv::_OutputArray* Rs, const cv::_OutputArray* Ts) {
		try {
			instance->getCameras(*Rs, *Ts);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_BaseSFM_setReconstructionOptions_const_libmv_ReconstructionOptionsX(cv::sfm::BaseSFM* instance, const cv::sfm::libmv_ReconstructionOptions* libmv_reconstruction_options) {
		try {
			instance->setReconstructionOptions(*libmv_reconstruction_options);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_BaseSFM_setCameraIntrinsicOptions_const_libmv_CameraIntrinsicsOptionsX(cv::sfm::BaseSFM* instance, const cv::sfm::libmv_CameraIntrinsicsOptions* libmv_camera_intrinsics_options) {
		try {
			instance->setCameraIntrinsicOptions(*libmv_camera_intrinsics_options);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_SFMLibmvEuclideanReconstruction_run_const__InputArrayX(cv::sfm::SFMLibmvEuclideanReconstruction* instance, const cv::_InputArray* points2d) {
		try {
			instance->run(*points2d);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_SFMLibmvEuclideanReconstruction_run_const__InputArrayX_const__InputOutputArrayX_const__OutputArrayX_const__OutputArrayX_const__OutputArrayX(cv::sfm::SFMLibmvEuclideanReconstruction* instance, const cv::_InputArray* points2d, const cv::_InputOutputArray* K, const cv::_OutputArray* Rs, const cv::_OutputArray* Ts, const cv::_OutputArray* points3d) {
		try {
			instance->run(*points2d, *K, *Rs, *Ts, *points3d);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_SFMLibmvEuclideanReconstruction_run_const_vector_String_X(cv::sfm::SFMLibmvEuclideanReconstruction* instance, const std::vector<cv::String>* images) {
		try {
			instance->run(*images);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_SFMLibmvEuclideanReconstruction_run_const_vector_String_X_const__InputOutputArrayX_const__OutputArrayX_const__OutputArrayX_const__OutputArrayX(cv::sfm::SFMLibmvEuclideanReconstruction* instance, const std::vector<cv::String>* images, const cv::_InputOutputArray* K, const cv::_OutputArray* Rs, const cv::_OutputArray* Ts, const cv::_OutputArray* points3d) {
		try {
			instance->run(*images, *K, *Rs, *Ts, *points3d);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result<double> cv_sfm_SFMLibmvEuclideanReconstruction_getError_const(const cv::sfm::SFMLibmvEuclideanReconstruction* instance) {
		try {
			double ret = instance->getError();
			return Ok(ret);
		} OCVRS_CATCH(Result<double>)
	}
	
	Result_void cv_sfm_SFMLibmvEuclideanReconstruction_getPoints_const__OutputArrayX(cv::sfm::SFMLibmvEuclideanReconstruction* instance, const cv::_OutputArray* points3d) {
		try {
			instance->getPoints(*points3d);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result<cv::Mat*> cv_sfm_SFMLibmvEuclideanReconstruction_getIntrinsics_const(const cv::sfm::SFMLibmvEuclideanReconstruction* instance) {
		try {
			cv::Mat ret = instance->getIntrinsics();
			return Ok(new cv::Mat(ret));
		} OCVRS_CATCH(Result<cv::Mat*>)
	}
	
	Result_void cv_sfm_SFMLibmvEuclideanReconstruction_getCameras_const__OutputArrayX_const__OutputArrayX(cv::sfm::SFMLibmvEuclideanReconstruction* instance, const cv::_OutputArray* Rs, const cv::_OutputArray* Ts) {
		try {
			instance->getCameras(*Rs, *Ts);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_SFMLibmvEuclideanReconstruction_setReconstructionOptions_const_libmv_ReconstructionOptionsX(cv::sfm::SFMLibmvEuclideanReconstruction* instance, const cv::sfm::libmv_ReconstructionOptions* libmv_reconstruction_options) {
		try {
			instance->setReconstructionOptions(*libmv_reconstruction_options);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result_void cv_sfm_SFMLibmvEuclideanReconstruction_setCameraIntrinsicOptions_const_libmv_CameraIntrinsicsOptionsX(cv::sfm::SFMLibmvEuclideanReconstruction* instance, const cv::sfm::libmv_CameraIntrinsicsOptions* libmv_camera_intrinsics_options) {
		try {
			instance->setCameraIntrinsicOptions(*libmv_camera_intrinsics_options);
			return Ok();
		} OCVRS_CATCH(Result_void)
	}
	
	Result<cv::Ptr<cv::sfm::SFMLibmvEuclideanReconstruction>*> cv_sfm_SFMLibmvEuclideanReconstruction_create_const_libmv_CameraIntrinsicsOptionsX_const_libmv_ReconstructionOptionsX(const cv::sfm::libmv_CameraIntrinsicsOptions* camera_instrinsic_options, const cv::sfm::libmv_ReconstructionOptions* reconstruction_options) {
		try {
			cv::Ptr<cv::sfm::SFMLibmvEuclideanReconstruction> ret = cv::sfm::SFMLibmvEuclideanReconstruction::create(*camera_instrinsic_options, *reconstruction_options);
			return Ok(new cv::Ptr<cv::sfm::SFMLibmvEuclideanReconstruction>(ret));
		} OCVRS_CATCH(Result<cv::Ptr<cv::sfm::SFMLibmvEuclideanReconstruction>*>)
	}
	
	Result<cv::sfm::libmv_CameraIntrinsicsOptions> cv_sfm_libmv_CameraIntrinsicsOptions_libmv_CameraIntrinsicsOptions_int_double_double_double_double_double_double_double_double(int _distortion_model, double _focal_length, double _principal_point_x, double _principal_point_y, double _polynomial_k1, double _polynomial_k2, double _polynomial_k3, double _polynomial_p1, double _polynomial_p2) {
		try {
			cv::sfm::libmv_CameraIntrinsicsOptions ret(_distortion_model, _focal_length, _principal_point_x, _principal_point_y, _polynomial_k1, _polynomial_k2, _polynomial_k3, _polynomial_p1, _polynomial_p2);
			return Ok(ret);
		} OCVRS_CATCH(Result<cv::sfm::libmv_CameraIntrinsicsOptions>)
	}
	
	Result<cv::sfm::libmv_ReconstructionOptions> cv_sfm_libmv_ReconstructionOptions_libmv_ReconstructionOptions_int_int_int_int_int(int _keyframe1, int _keyframe2, int _refine_intrinsics, int _select_keyframes, int _verbosity_level) {
		try {
			cv::sfm::libmv_ReconstructionOptions ret(_keyframe1, _keyframe2, _refine_intrinsics, _select_keyframes, _verbosity_level);
			return Ok(ret);
		} OCVRS_CATCH(Result<cv::sfm::libmv_ReconstructionOptions>)
	}
	
}
