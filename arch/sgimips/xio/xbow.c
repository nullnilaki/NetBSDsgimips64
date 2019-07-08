/*
 * Bus access primitives.
 */

void
xbow_build_bus_space(struct mips_bus_space *bs, int nasid, int widget)
{
    bcopy(&xbowbus_tag, bs, sizeof (*bs));
    bs->bus_base = (*xbow_widget_base)(nasid, widget);
}
