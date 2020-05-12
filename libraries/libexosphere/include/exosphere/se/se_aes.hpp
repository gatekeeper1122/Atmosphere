/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <vapours.hpp>
#include <exosphere/se/se_common.hpp>

namespace ams::se {

    constexpr inline int AesKeySlotCount = 16;
    constexpr inline size_t AesBlockSize = crypto::AesEncryptor128::BlockSize;

    void ClearAesKeySlot(int slot);
    void LockAesKeySlot(int slot, u32 flags);

    void SetAesKey(int slot, const void *key, size_t key_size);

    void SetEncryptedAesKey128(int dst_slot, int kek_slot, const void *key, size_t key_size);
    void SetEncryptedAesKey256(int dst_slot, int kek_slot, const void *key, size_t key_size);

    void EncryptAes128(void *dst, size_t dst_size, int slot, const void *src, size_t src_size);
    void DecryptAes128(void *dst, size_t dst_size, int slot, const void *src, size_t src_size);

    void ComputeAes128Ctr(void *dst, size_t dst_size, int slot, const void *src, size_t src_size, const void *iv, size_t iv_size);

}
