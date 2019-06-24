/*	$NetBSD: pmu.h,v 1.3 2018/08/27 07:35:31 riastradh Exp $	*/

#ifndef __NVKM_PMU_H__
#define __NVKM_PMU_H__
#include <core/subdev.h>

struct nvkm_pmu {
	const struct nvkm_pmu_func *func;
	struct nvkm_subdev subdev;

	struct {
		u32 base;
		u32 size;
	} send;

	struct {
		u32 base;
		u32 size;

		struct work_struct work;
#ifdef __NetBSD__
		drm_waitqueue_t wait;
#else
		wait_queue_head_t wait;
#endif
		u32 process;
		u32 message;
		u32 data[2];
	} recv;
};

int nvkm_pmu_send(struct nvkm_pmu *, u32 reply[2], u32 process,
		  u32 message, u32 data0, u32 data1);
void nvkm_pmu_pgob(struct nvkm_pmu *, bool enable);

int gt215_pmu_new(struct nvkm_device *, int, struct nvkm_pmu **);
int gf100_pmu_new(struct nvkm_device *, int, struct nvkm_pmu **);
int gf119_pmu_new(struct nvkm_device *, int, struct nvkm_pmu **);
int gk104_pmu_new(struct nvkm_device *, int, struct nvkm_pmu **);
int gk110_pmu_new(struct nvkm_device *, int, struct nvkm_pmu **);
int gk208_pmu_new(struct nvkm_device *, int, struct nvkm_pmu **);
int gk20a_pmu_new(struct nvkm_device *, int, struct nvkm_pmu **);
int gm107_pmu_new(struct nvkm_device *, int, struct nvkm_pmu **);

/* interface to MEMX process running on PMU */
struct nvkm_memx;
int  nvkm_memx_init(struct nvkm_pmu *, struct nvkm_memx **);
int  nvkm_memx_fini(struct nvkm_memx **, bool exec);
void nvkm_memx_wr32(struct nvkm_memx *, u32 addr, u32 data);
void nvkm_memx_wait(struct nvkm_memx *, u32 addr, u32 mask, u32 data, u32 nsec);
void nvkm_memx_nsec(struct nvkm_memx *, u32 nsec);
void nvkm_memx_wait_vblank(struct nvkm_memx *);
void nvkm_memx_train(struct nvkm_memx *);
int  nvkm_memx_train_result(struct nvkm_pmu *, u32 *, int);
void nvkm_memx_block(struct nvkm_memx *);
void nvkm_memx_unblock(struct nvkm_memx *);
#endif
