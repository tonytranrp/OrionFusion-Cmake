
class ItemInHandRenderer : public ActorShaderManager { /* Size=0x440 */
  /* 0x0000: fields for ActorShaderManager */
  /* 0x0038 */ ItemStack mItem;
  /* 0x0130 */ ItemStack mOffHandItem;
  /* 0x0228 */ int32_t mSlot;
  /* 0x0230 */ IClientInstance& mClient;
  /* 0x0238 */ std::unique_ptr<TextureTessellator,std::default_delete<TextureTessellator> > mTextureTessellator;
  /* 0x0240 */ float mHeight;
  /* 0x0244 */ float mOldHeight;
  /* 0x0248 */ float mHeightOffHand;
  /* 0x024c */ float mOldHeightOffHand;
  /* 0x0250 */ BlockTessellator& mBlockTessellator;
  /* 0x0258 */ mce::MaterialPtr mMatOpaqueBlock;
  /* 0x0268 */ mce::MaterialPtr mMatOpaqueBlockColor;
  /* 0x0278 */ mce::MaterialPtr mMatAlphaBlock;
  /* 0x0288 */ mce::MaterialPtr mMatItem;
  /* 0x0298 */ mce::MaterialPtr mMatBlendBlock;
  /* 0x02a8 */ mce::MaterialPtr mMatBlendBlockNoColor;
  /* 0x02b8 */ mce::MaterialPtr mMatAlphaColoredBlock;
  /* 0x02c8 */ mce::MaterialPtr mMatItemMultiColorTint;
  /* 0x02d8 */ mce::MaterialPtr mMatOpaqueBlockGlint;
  /* 0x02e8 */ mce::MaterialPtr mMatAlphaBlockGlint;
  /* 0x02f8 */ mce::MaterialPtr mMatItemGlint;
  /* 0x0308 */ mce::MaterialPtr mMatFishingLine;
  /* 0x0318 */ std::array<mce::MaterialPtr const *,8> mMaterialMatrix;
  /* 0x0358 */ mce::TexturePtr mGlintTexture;
  /* 0x03a0 */ std::unique_ptr<BannerBlockActor,std::default_delete<BannerBlockActor> > mBannerEntity;
  /* 0x03a8 */ std::unique_ptr<ConduitBlockActor,std::default_delete<ConduitBlockActor> > mConduitEntity;
  /* 0x03b0 */ std::map<ItemInHandRenderer::FrameId,ItemRenderCall,std::less<ItemInHandRenderer::FrameId>,std::allocator<std::pair<ItemInHandRenderer::FrameId const ,ItemRenderCall> > > mRenderObjects;
  /* 0x03c0 */ std::unordered_map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,ItemRenderCall,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,ItemRenderCall> > > mStrRenderObjects;
  /* 0x0400 */ Matrix mTransform;
  static Vec3 neteaseBowTranslate;
  
  ItemInHandRenderer(IClientInstance&, BlockTessellator&, mce::TextureGroup&);
  virtual ~ItemInHandRenderer();
  void initMaterials(mce::TextureGroup&);
  void shutdown();
  void tick();
  void render(BaseActorRenderContext&, ItemContextFlags);
  void renderItem(BaseActorRenderContext&, Actor&, const ItemStack&, bool, ItemContextFlags, bool);
  void renderItemNew(BaseActorRenderContext&, Actor&, const ItemStack&, ItemContextFlags);
  void renderOffhandItem(BaseActorRenderContext&, Player&, ItemContextFlags);
  void renderFoil(BaseActorRenderContext&, Actor&, ItemRenderCall*);
  void renderObject(BaseActorRenderContext&, const ItemRenderCall&, const dragon::RenderMetadata&, ItemContextFlags);
  const mce::MaterialPtr& getObjectMaterial(const ItemRenderCall&, ItemContextFlags) const;
  const mce::TexturePtr& getObjectTexture(const ItemRenderCall&, bool) const;
  void onItemUsed();
  void clearRenderObjects();
  const ItemRenderCall& getRenderCallAtFrame(BaseActorRenderContext&, const ItemStack&, int32_t);
  void tessellateAtFrame(BaseActorRenderContext&, Mob*, const ItemStack&, int32_t);
  const ItemStack& getMainHandItem() const;
  const ItemStack& getOffHandItem() const;
  void clearItemRenderCalls(const Item&);
  ItemRenderCall& _rebuildItem(BaseActorRenderContext&, Mob*, const ItemStack&, int32_t);
  bool _canTessellateAsBlockItem(const ItemStack&) const;
  void _tessellateBlockItem(Tessellator&, BlockTessellator&, const Block&);
  void _tessellateTextureItem(BaseActorRenderContext&, TextureTessellator&, Mob*, const ItemStack&, int32_t, uint16_t&, uint16_t&);
  ItemInHandRenderer::FrameId _getFrameID(Mob*, const ItemStack&, int32_t);
  const dragon::RenderMetadata _createRenderMetadata(BaseActorRenderContext&, Actor&);
  ItemRenderCall* _getRenderCall(Mob*, const ItemStack&, int32_t);
  void _setPlayerBob(LocalPlayer*, float, Matrix&);
  void _renderMiniMapHand(BaseActorRenderContext&, Player&, bool);
  void _renderMapInHands(BaseActorRenderContext&, Player&, const float, const float, const float);
  void _renderMapInOneHand(BaseActorRenderContext&, Player&, const float, const float, const float, const bool);
  void _renderMapInOffhand(BaseActorRenderContext&, Player&, const float, const float, const float);
  void _renderMapInMainHand(BaseActorRenderContext&, Player&, const float, const float, const float);
  bool _isUsingVR(BaseActorRenderContext&) const;
  bool _adjustHandPositionForVR(MatrixStack::MatrixStackRef&, bool, float);
  void _renderItemRepositionByJSON(BaseActorRenderContext&, const ItemStack&, MatrixStack::MatrixStackRef&);
  void _pushSparklerParticles(BaseActorRenderContext&, const ItemStack&, Level&);
  const mce::MaterialPtr* _fetchMaterialFor(const ItemRenderCall&) const;
  void _transformOffhandTool(MatrixStack::MatrixStackRef&, const ItemStack&, float);
  void _transformOffhandItem(MatrixStack::MatrixStackRef&);
  void _transformActivatedShield(MatrixStack::MatrixStackRef&, const Player&, float, float, float);
  Vec3 _calculateOffhandWorldTranslation(const Player&, const BaseActorRenderContext&) const;
  Vec3 _getScreenRatioAdjustment(const BaseActorRenderContext&, Vec3, float, float) const;
  InHandUpdateType _checkAndUpdateIfItemChanged(ItemStack&, const ItemStack&, const bool, const bool);
  bool _areNotMatchingChemistrySticks(ItemStack&, const ItemStack&);
  void __autoclassinit2(uint64_t);
  virtual void* __vecDelDtor(uint32_t);
};